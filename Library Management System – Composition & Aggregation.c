"""
Library Management System demonstrating:
- Composition (Book, Member, Library)
- Aggregation (Library has many Books and Members)
- Encapsulation (private members, properties)
- Custom exceptions
- Context manager for file operations (persistence)
"""

import json
import os
from datetime import datetime, timedelta
from typing import List, Dict, Optional
from enum import Enum


class BookStatus(Enum):
    AVAILABLE = "Available"
    BORROWED = "Borrowed"
    RESERVED = "Reserved"
    LOST = "Lost"


class Book:
    """Represents a book in the library."""
    
    def __init__(self, isbn: str, title: str, author: str, year: int, copies: int = 1):
        self._isbn = isbn
        self._title = title
        self._author = author
        self._year = year
        self._total_copies = copies
        self._available_copies = copies
        self._status = BookStatus.AVAILABLE
        self._borrow_history: List[Dict] = []
    
    @property
    def isbn(self) -> str:
        return self._isbn
    
    @property
    def title(self) -> str:
        return self._title
    
    @property
    def author(self) -> str:
        return self._author
    
    @property
    def available_copies(self) -> int:
        return self._available_copies
    
    @property
    def total_copies(self) -> int:
        return self._total_copies
    
    def is_available(self) -> bool:
        return self._available_copies > 0
    
    def borrow_copy(self, member_id: str) -> bool:
        """Borrow one copy of the book."""
        if self._available_copies > 0:
            self._available_copies -= 1
            self._borrow_history.append({
                "member_id": member_id,
                "borrow_date": datetime.now().isoformat(),
                "return_date": None
            })
            self._update_status()
            return True
        return False
    
    def return_copy(self, member_id: str) -> bool:
        """Return one copy of the book."""
        # Find the most recent unreturned borrow by this member
        for record in reversed(self._borrow_history):
            if record["member_id"] == member_id and record["return_date"] is None:
                record["return_date"] = datetime.now().isoformat()
                self._available_copies += 1
                self._update_status()
                return True
        return False
    
    def _update_status(self) -> None:
        """Update the book's status based on available copies."""
        if self._available_copies == 0:
            self._status = BookStatus.BORROWED
        else:
            self._status = BookStatus.AVAILABLE
    
    def add_copies(self, num: int) -> None:
        """Add more copies of the book."""
        if num > 0:
            self._total_copies += num
            self._available_copies += num
            self._update_status()
    
    def to_dict(self) -> dict:
        return {
            "isbn": self._isbn,
            "title": self._title,
            "author": self._author,
            "year": self._year,
            "total_copies": self._total_copies,
            "available_copies": self._available_copies,
            "borrow_history": self._borrow_history
        }
    
    def __str__(self) -> str:
        return f"{self._title} by {self._author} (ISBN: {self._isbn}) - {self._status.value} ({self._available_copies}/{self._total_copies} copies)"


class Member:
    """Represents a library member."""
    
    def __init__(self, member_id: str, name: str, email: str):
        self._member_id = member_id
        self._name = name
        self._email = email
        self._borrowed_books: List[str] = []  # ISBNs of currently borrowed books
        self._reserved_books: List[str] = []
        self._membership_active = True
        self._join_date = datetime.now()
        self._fine_amount = 0.0
    
    @property
    def member_id(self) -> str:
        return self._member_id
    
    @property
    def name(self) -> str:
        return self._name
    
    @property
    def email(self) -> str:
        return self._email
    
    @property
    def fine(self) -> float:
        return self._fine_amount
    
    def can_borrow(self) -> bool:
        """Check if member can borrow more books."""
        return self._membership_active and len(self._borrowed_books) < 5 and self._fine_amount == 0
    
    def borrow_book(self, isbn: str) -> bool:
        if self.can_borrow() and isbn not in self._borrowed_books:
            self._borrowed_books.append(isbn)
            return True
        return False
    
    def return_book(self, isbn: str) -> bool:
        if isbn in self._borrowed_books:
            self._borrowed_books.remove(isbn)
            return True
        return False
    
    def add_fine(self, amount: float) -> None:
        self._fine_amount += amount
    
    def pay_fine(self, amount: float) -> None:
        if amount <= self._fine_amount:
            self._fine_amount -= amount
        else:
            self._fine_amount = 0
    
    def to_dict(self) -> dict:
        return {
            "member_id": self._member_id,
            "name": self._name,
            "email": self._email,
            "borrowed_books": self._borrowed_books,
            "membership_active": self._membership_active,
            "join_date": self._join_date.isoformat(),
            "fine": self._fine_amount
        }
    
    def __str__(self) -> str:
        status = "Active" if self._membership_active else "Suspended"
        return f"Member: {self._name} ({self._member_id}) - {status}, Fine: ${self._fine_amount:.2f}, Borrowed: {len(self._borrowed_books)} books"


class Library:
    """Main library class that manages books and members (composition)."""
    
    def __init__(self, name: str):
        self._name = name
        self._books: Dict[str, Book] = {}      # ISBN -> Book
        self._members: Dict[str, Member] = {}  # member_id -> Member
        self._transactions: List[Dict] = []
    
    def add_book(self, book: Book) -> None:
        if book.isbn in self._books:
            # Add copies instead of duplicate
            self._books[book.isbn].add_copies(book.total_copies)
        else:
            self._books[book.isbn] = book
    
    def remove_book(self, isbn: str) -> bool:
        if isbn in self._books:
            del self._books[isbn]
            return True
        return False
    
    def register_member(self, member: Member) -> None:
        if member.member_id not in self._members:
            self._members[member.member_id] = member
    
    def borrow_book(self, member_id: str, isbn: str) -> bool:
        """Process borrowing a book."""
        if member_id not in self._members:
            print("Member not found.")
            return False
        if isbn not in self._books:
            print("Book not found.")
            return False
        
        member = self._members[member_id]
        book = self._books[isbn]
        
        if not member.can_borrow():
            print(f"{member.name} cannot borrow (limit reached or fine pending).")
            return False
        
        if not book.is_available():
            print(f"'{book.title}' is not available.")
            return False
        
        if book.borrow_copy(member_id):
            if member.borrow_book(isbn):
                self._transactions.append({
                    "type": "borrow",
                    "member_id": member_id,
                    "isbn": isbn,
                    "date": datetime.now().isoformat()
                })
                print(f"{member.name} borrowed '{book.title}'.")
                return True
            else:
                # Rollback book borrow if member failed
                book.return_copy(member_id)
        
        return False
    
    def return_book(self, member_id: str, isbn: str, days_late: int = 0) -> bool:
        """Process returning a book, optionally with late fine."""
        if member_id not in self._members or isbn not in self._books:
            return False
        
        member = self._members[member_id]
        book = self._books[isbn]
        
        if book.return_copy(member_id):
            if member.return_book(isbn):
                if days_late > 0:
                    fine = days_late * 0.50  # $0.50 per day late
                    member.add_fine(fine)
                    print(f"Late return! Fine of ${fine:.2f} added.")
                
                self._transactions.append({
                    "type": "return",
                    "member_id": member_id,
                    "isbn": isbn,
                    "date": datetime.now().isoformat(),
                    "days_late": days_late
                })
                print(f"{member.name} returned '{book.title}'.")
                return True
        return False
    
    def search_books(self, query: str) -> List[Book]:
        """Search books by title or author (case-insensitive)."""
        query_lower = query.lower()
        results = []
        for book in self._books.values():
            if query_lower in book.title.lower() or query_lower in book.author.lower():
                results.append(book)
        return results
    
    def get_member_borrowed_books(self, member_id: str) -> List[Book]:
        """Get all books currently borrowed by a member."""
        if member_id not in self._members:
            return []
        borrowed_isbns = self._members[member_id]._borrowed_books
        return [self._books[isbn] for isbn in borrowed_isbns if isbn in self._books]
    
    def save_to_file(self, filename: str) -> None:
        """Save library data to a JSON file."""
        data = {
            "name": self._name,
            "books": {isbn: book.to_dict() for isbn, book in self._books.items()},
            "members": {mid: member.to_dict() for mid, member in self._members.items()},
            "transactions": self._transactions
        }
        with open(filename, 'w') as f:
            json.dump(data, f, indent=2)
        print(f"Library data saved to {filename}")
    
    def display_available_books(self) -> None:
        print(f"\n=== {self._name} - Available Books ===")
        for book in self._books.values():
            if book.is_available():
                print(f"  {book}")
    
    def __len__(self) -> int:
        return len(self._books)


# Demonstration
if __name__ == "__main__":
    # Create library
    library = Library("City Central Library")
    
    # Add books
    book1 = Book("978-0132350884", "Clean Code", "Robert C. Martin", 2008, 3)
    book2 = Book("978-1491946008", "Fluent Python", "Luciano Ramalho", 2015, 2)
    book3 = Book("978-0596007126", "The Art of Unix Programming", "Eric S. Raymond", 2003, 1)
    library.add_book(book1)
    library.add_book(book2)
    library.add_book(book3)
    
    # Register members
    member1 = Member("M001", "Alice Wonderland", "alice@example.com")
    member2 = Member("M002", "Bob Builder", "bob@example.com")
    library.register_member(member1)
    library.register_member(member2)
    
    # Borrow and return operations
    library.borrow_book("M001", "978-0132350884")  # Alice borrows Clean Code
    library.borrow_book("M002", "978-0132350884")  # Bob borrows another copy
    library.borrow_book("M001", "978-1491946008")  # Alice borrows Fluent Python
    
    library.display_available_books()
    
    # Return a book late
    library.return_book("M001", "978-0132350884", days_late=3)  # 3 days late -> $1.50 fine
    
    # Display member info
    print("\nMember details:")
    for mid in ["M001", "M002"]:
        print(library._members[mid])
    
    # Search books
    print("\nSearch for 'Python':")
    for book in library.search_books("Python"):
        print(f"  {book}")
    
    # Save to file
    library.save_to_file("library_data.json")
    
    print(f"\nTotal books in library: {len(library)}")