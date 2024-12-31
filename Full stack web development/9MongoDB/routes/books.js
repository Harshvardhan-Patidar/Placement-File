const express = require("express");
const router = express.Router();
const { books } = require("../data/books.json");
const {UserModel,BookModel}=require("../models/localIndex");
const { getAllBooks, getSingleBookById } = require("../controllers/book-controller");

router.get("/",getAllBooks)
router.get("/:id",getSingleBookById)

