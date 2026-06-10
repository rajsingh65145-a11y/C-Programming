"""
Vehicle Management System demonstrating:
- Multiple inheritance (ElectricVehicle mixin)
- Method resolution order (MRO)
- Abstract base classes
- Property decorators and validation
- Class composition (Engine, Battery as separate classes)
"""

from abc import ABC, abstractmethod
from typing import Optional
import math


# ---- Component classes (composition) ----
class Engine:
    """Represents a combustion engine."""
    
    def __init__(self, horsepower: int, cylinders: int, displacement: float):
        self._horsepower = horsepower
        self._cylinders = cylinders
        self._displacement = displacement  # in liters
        self._is_running = False
    
    def start(self) -> None:
        if not self._is_running:
            self._is_running = True
            print(f"Engine started ({self._horsepower} HP, {self._cylinders} cyl, {self._displacement}L).")
    
    def stop(self) -> None:
        if self._is_running:
            self._is_running = False
            print("Engine stopped.")
    
    @property
    def horsepower(self) -> int:
        return self._horsepower
    
    def __str__(self) -> str:
        return f"Engine({self._horsepower}HP)"


class Battery:
    """Represents an electric battery."""
    
    def __init__(self, capacity_kwh: float, max_voltage: float):
        self._capacity_kwh = capacity_kwh  # total energy capacity
        self._current_charge_kwh = capacity_kwh
        self._max_voltage = max_voltage
        self._temperature_celsius = 25.0
    
    def charge(self, amount_kwh: float) -> None:
        if amount_kwh > 0:
            self._current_charge_kwh = min(self._capacity_kwh, self._current_charge_kwh + amount_kwh)
            print(f"Charged {amount_kwh} kWh. Battery at {self.charge_percentage():.1f}%")
    
    def discharge(self, amount_kwh: float) -> bool:
        if amount_kwh <= self._current_charge_kwh:
            self._current_charge_kwh -= amount_kwh
            self._temperature_celsius += amount_kwh * 0.5  # simple heating model
            return True
        return False
    
    def charge_percentage(self) -> float:
        return (self._current_charge_kwh / self._capacity_kwh) * 100
    
    @property
    def remaining_range_km(self) -> float:
        """Assume 6 km per kWh efficiency."""
        return self._current_charge_kwh * 6
    
    def __str__(self) -> str:
        return f"Battery({self._current_charge_kwh:.1f}/{self._capacity_kwh:.1f} kWh)"


# ---- Mixin classes ----
class ElectricMixin:
    """Mixin to add electric capabilities."""
    
    def __init__(self, battery: Battery, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self._battery = battery
    
    def charge_battery(self, kwh: float) -> None:
        self._battery.charge(kwh)
    
    def get_battery_status(self) -> str:
        return str(self._battery)
    
    def electric_range(self) -> float:
        return self._battery.remaining_range_km


class ConvertibleMixin:
    """Mixin for convertible cars."""
    
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self._roof_open = False
    
    def open_roof(self) -> None:
        if not self._roof_open:
            self._roof_open = True
            print("Roof opened.")
    
    def close_roof(self) -> None:
        if self._roof_open:
            self._roof_open = False
            print("Roof closed.")


# ---- Abstract base class ----
class Vehicle(ABC):
    """Abstract base class for all vehicles."""
    
    def __init__(self, make: str, model: str, year: int, vin: str):
        self._make = make
        self._model = model
        self._year = year
        self._vin = vin
        self._odometer_km = 0.0
        self._fuel_efficiency_l_per_100km: Optional[float] = None  # L/100km
    
    @property
    def make(self) -> str:
        return self._make
    
    @property
    def model(self) -> str:
        return self._model
    
    @property
    def vin(self) -> str:
        return self._vin
    
    @property
    def odometer(self) -> float:
        return self._odometer_km
    
    def drive(self, distance_km: float) -> None:
        """Drive the vehicle a given distance."""
        if distance_km <= 0:
            raise ValueError("Distance must be positive")
        fuel_needed = self._calculate_fuel_needed(distance_km)
        if self._has_enough_fuel(fuel_needed):
            self._odometer_km += distance_km
            self._consume_fuel(fuel_needed)
            print(f"Drove {distance_km} km. Odometer: {self._odometer_km:.1f} km")
        else:
            print("Insufficient fuel/charge for this distance.")
    
    @abstractmethod
    def _calculate_fuel_needed(self, distance_km: float) -> float:
        """Calculate fuel/energy needed for a distance."""
        pass
    
    @abstractmethod
    def _has_enough_fuel(self, amount: float) -> bool:
        pass
    
    @abstractmethod
    def _consume_fuel(self, amount: float) -> None:
        pass
    
    def __str__(self) -> str:
        return f"{self._year} {self._make} {self._model} (VIN: {self._vin})"


# ---- Concrete vehicle classes ----
class Car(Vehicle):
    """Standard car with an engine."""
    
    def __init__(self, make: str, model: str, year: int, vin: str, engine: Engine, fuel_capacity_l: float):
        super().__init__(make, model, year, vin)
        self._engine = engine
        self._fuel_capacity_l = fuel_capacity_l
        self._fuel_level_l = fuel_capacity_l  # start full
        self._fuel_efficiency_l_per_100km = 8.5  # default
    
    def _calculate_fuel_needed(self, distance_km: float) -> float:
        return (distance_km / 100.0) * self._fuel_efficiency_l_per_100km
    
    def _has_enough_fuel(self, amount: float) -> bool:
        return amount <= self._fuel_level_l
    
    def _consume_fuel(self, amount: float) -> None:
        self._fuel_level_l -= amount
    
    def refuel(self, liters: float) -> None:
        if liters > 0:
            self._fuel_level_l = min(self._fuel_capacity_l, self._fuel_level_l + liters)
            print(f"Refueled {liters}L. Fuel level: {self._fuel_level_l:.1f}/{self._fuel_capacity_l}L")
    
    def start_engine(self) -> None:
        self._engine.start()
    
    def stop_engine(self) -> None:
        self._engine.stop()


class ElectricCar(Car, ElectricMixin):
    """Car that is fully electric (multiple inheritance)."""
    
    def __init__(self, make: str, model: str, year: int, vin: str, battery: Battery):
        # Need to call Car's __init__ (which also calls Vehicle __init__) and ElectricMixin's __init__
        # We'll create a dummy engine for the Car part (electric cars have no engine)
        dummy_engine = Engine(0, 0, 0.0)
        Car.__init__(self, make, model, year, vin, dummy_engine, fuel_capacity_l=0)
        ElectricMixin.__init__(self, battery)
        # Override efficiency for electric (kWh per 100 km)
        self._kwh_per_100km = 16.0  # typical efficiency
    
    def _calculate_fuel_needed(self, distance_km: float) -> float:
        # Returns kWh needed
        return (distance_km / 100.0) * self._kwh_per_100km
    
    def _has_enough_fuel(self, amount: float) -> bool:
        # amount here is kWh required
        return amount <= self._battery._current_charge_kwh
    
    def _consume_fuel(self, amount: float) -> None:
        self._battery.discharge(amount)
    
    def refuel(self, liters: float) -> None:
        print("This car is electric. Use charge_battery() instead.")
    
    def start_engine(self) -> None:
        print("Electric car: silent start.")
    
    def stop_engine(self) -> None:
        print("Electric car: silent stop.")


class Motorcycle(Vehicle):
    """Two-wheeled vehicle."""
    
    def __init__(self, make: str, model: str, year: int, vin: str, engine: Engine, tank_capacity_l: float):
        super().__init__(make, model, year, vin)
        self._engine = engine
        self._tank_capacity_l = tank_capacity_l
        self._fuel_level_l = tank_capacity_l
        self._has_sidecar = False
        self._fuel_efficiency_l_per_100km = 5.5
    
    def attach_sidecar(self) -> None:
        self._has_sidecar = True
        self._fuel_efficiency_l_per_100km = 7.0  # less efficient
        print("Sidecar attached.")
    
    def _calculate_fuel_needed(self, distance_km: float) -> float:
        return (distance_km / 100.0) * self._fuel_efficiency_l_per_100km
    
    def _has_enough_fuel(self, amount: float) -> bool:
        return amount <= self._fuel_level_l
    
    def _consume_fuel(self, amount: float) -> None:
        self._fuel_level_l -= amount
    
    def refuel(self, liters: float) -> None:
        if liters > 0:
            self._fuel_level_l = min(self._tank_capacity_l, self._fuel_level_l + liters)
            print(f"Refueled {liters}L. Fuel level: {self._fuel_level_l:.1f}/{self._tank_capacity_l}L")


class ElectricMotorcycle(Motorcycle, ElectricMixin):
    """Electric motorcycle using multiple inheritance."""
    
    def __init__(self, make: str, model: str, year: int, vin: str, battery: Battery):
        # Dummy engine for Motorcycle parent
        dummy_engine = Engine(0, 0, 0.0)
        Motorcycle.__init__(self, make, model, year, vin, dummy_engine, tank_capacity_l=0)
        ElectricMixin.__init__(self, battery)
        self._kwh_per_100km = 11.0
    
    def _calculate_fuel_needed(self, distance_km: float) -> float:
        return (distance_km / 100.0) * self._kwh_per_100km
    
    def _has_enough_fuel(self, amount: float) -> bool:
        return amount <= self._battery._current_charge_kwh
    
    def _consume_fuel(self, amount: float) -> None:
        self._battery.discharge(amount)
    
    def refuel(self, liters: float) -> None:
        print("Use charge_battery() instead.")
    
    def start_engine(self) -> None:
        print("Electric motorcycle ready (silent).")


# Demonstration
if __name__ == "__main__":
    # Create a regular car
    v6_engine = Engine(250, 6, 3.5)
    sedan = Car("Toyota", "Camry", 2022, "1HGBH41JXMN109186", v6_engine, 55.0)
    sedan.start_engine()
    sedan.drive(120)
    sedan.refuel(20)
    sedan.drive(300)
    sedan.stop_engine()
    print(sedan)
    
    print("\n" + "="*50 + "\n")
    
    # Create an electric car (multiple inheritance)
    tesla_battery = Battery(75.0, 400)
    tesla = ElectricCar("Tesla", "Model 3", 2023, "5YJ3E1EA7PF123456", tesla_battery)
    tesla.start_engine()  # Silent start
    print(f"Range: {tesla.electric_range():.1f} km")
    tesla.drive(200)
    tesla.charge_battery(30)
    print(tesla.get_battery_status())
    print(tesla)
    
    print("\n" + "="*50 + "\n")
    
    # Create a motorcycle
    bike_engine = Engine(100, 2, 0.65)
    bike = Motorcycle("Harley-Davidson", "Iron 883", 2021, "1HD1ZK123456789", bike_engine, 12.5)
    bike.attach_sidecar()
    bike.drive(80)
    bike.refuel(5)
    print(bike)
    
    print("\n" + "="*50 + "\n")
    
    # Electric motorcycle using mixin
    e_bike_battery = Battery(15.0, 72)
    e_bike = ElectricMotorcycle("Zero", "SR/F", 2024, "ZERO123456789", e_bike_battery)
    e_bike.charge_battery(10)
    e_bike.drive(60)
    print(f"Electric bike range: {e_bike.electric_range():.1f} km")
    print(e_bike.get_battery_status())
    print(e_bike)
    
    # Show Method Resolution Order
    print("\nMRO for ElectricCar:", [cls.__name__ for cls in ElectricCar.__mro__])