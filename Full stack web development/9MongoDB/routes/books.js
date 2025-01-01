const express = require("express");
const router = express.Router();
const {UserModel,BookModel}=require("../models/localIndex");
const { getAllBooks, getSingleBookById, getAllIssuedBooks, addNewBook, updateBookById } = require("../controllers/book-controller");

router.get("/",getAllBooks)
router.get("/:id",getSingleBookById)
router.get("/issued",getAllIssuedBooks)
router.post("/",addNewBook)
router.post("/update",updateBookById)

