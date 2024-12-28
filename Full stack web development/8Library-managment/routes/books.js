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
    const issuedBook=[];
    users.forEach((iterate) => {
      bookIssued = books.find((element) => iterate.issuedBook == element.name);
      issuedBook.push(bookIssued);
    });
    
    if(issuedBook.length==0){
      return res.status(404).json({
        success:false,
        message:"No book have been issued",
      })
    }
    res.status(200).json({
      success: true,
      issuedBook,
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

// method: put
// route: /books/:id (updateing the book data)
router.put("/:id", (req, res) => {
    const id = req.params;
    const data = req.body;
    const book = books.find((iterate) => iterate.id == id);
    if (!book) {
      return res.status(404).json({
        success: false,
        message: "Book not found",
      });
    }
  
    const updateBookData = books.map((iterate) => {
      if (iterate.id == id) {
        return {
          ...iterate,
          ...data,
        };
      }
      return iterate;
    });
  
    res.status(200).json({
      success: true,
      message: "Data updated",
    });
  });

module.exports=router;