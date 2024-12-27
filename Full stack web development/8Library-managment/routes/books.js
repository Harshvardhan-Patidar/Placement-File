const express=require("express")
const router=express.Router();
const { books } = require("../data/books.json");

// method: get
// route: /books
router.get("/", (req, res) => {
    res.status(200).json({
      success: true,
      data: books,
    });
  });
  
  // route: /books/:id
  router.get("/:id", (req, res) => {
    const id = req.params;
    const book = books.find((iterate) => iterate.id == id);
    if (!book) {
      return res.status(404).json({
        success: false,
        message: "Book not found",
      });
    }
  
    res.status(202).json({
      success: true,
      book,
    });
  });
  
  // route: /books/issued
  router.get("/issued", (req, res) => {
    var bookIssued;
    users.forEach((iterate) => {
      bookIssued = books.forEach((element) => iterate.issuedBook == element.name);
    });
  
    res.status(200).json({
      success: true,
      bookIssued,
    });
  });

// method: post 
// route: /books
router.post("/", (req, re) => {
    const { id, name, author, genre, price, publisher } = req.body;
    const book = books.find((iterate) => iterate.id == id);
    if (book) {
      return res.status(404).json({
        success: false,
        message: "Book already found",
      });
    }
  
    books.push({ id, name, author, genre, price, publisher });
  
    res.status(200).json({
      success: true,
      message: "Book added",
    });
  });

// method:

module.exports=router;