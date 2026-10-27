# Write your MySQL query statement below
select e.name 
from employee as e
where id in (
    select managerId
    from employee
    group by managerId
    having count(managerId)>=5
)