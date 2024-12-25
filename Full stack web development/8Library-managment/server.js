const express = require("express");
const { users } = require("./data/users.json");
const { books } = require("./data/books.json");
const app = express();
app.use(express.json());
const PORT = 8081;

app.get("/", (req, res) => {
  res.status(200).json({
    message: "Server is up and running",
  });
});

// route: /users
// methos: get
// discription: show all users information
app.get("/users",(req,res)=>{
    res.status(200).json({
        success: true,
        data:  users,
    })
})

app.get("*", (req, res) => {
  res.status(200).json({
    message: "This route does not exit",
  });
});

app.listen(PORT, () => {
  console.log("Server is running on PORT:", PORT);
});
