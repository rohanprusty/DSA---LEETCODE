# Write your MySQL query statement below
select name , bonus
from employee
left join Bonus
on employee.empId = Bonus.empId
where bonus< 1000 or bonus is null
