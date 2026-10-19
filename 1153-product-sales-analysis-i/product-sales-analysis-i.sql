# Write your MySQL query statement below
select product_name , year , price
from product
inner join sales
on sales.product_id = product.product_id