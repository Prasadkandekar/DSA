SELECT customer_id , Count(*) as count_no_trans
FROM Visits
Where visit_id NOT IN(
    SELECT visit_id
    FROM Transactions
)
GROUP BY customer_id;
