# Write your MySQL query statement below
Select e.name,b.bonus
From Employee e
Left Join Bonus b
on e.empId = b.empId Where bonus < 1000 OR bonus is null;