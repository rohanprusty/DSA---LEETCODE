# Write your MySQL query statement below
SELECT DISTINCT author_id AS id
fROM Views
WHERE  author_id = viewer_id
order by id ASC