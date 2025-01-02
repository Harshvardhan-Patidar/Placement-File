const express = require("express");
const {getAllUsers,updateUserData} = require("../controllers/user-controller");
const router = express.Router();


// In user.js no extra route is create but in books.js all routes is create refer "books.js" file
// beause maximum logic is same
router.get("/",getAllUsers);
router.put("/:id",updateUserData);