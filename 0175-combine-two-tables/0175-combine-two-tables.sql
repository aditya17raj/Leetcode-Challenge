# Write your MySQL query statement below
SELECT P.firstName , p.lastName , A.city , A.state
FROM Person as P
LEFT JOIN Address as A
ON P.personId = A.personId;