# Write your MySQL query statement below
SELECT c.customer_id
FROM Customer c
Join Product p
on c.product_key = p.product_key
Group By c.customer_id
Having count(DISTINCT c.product_key)= (SELECT count(*) from Product);
