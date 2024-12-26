const express = require("express");
const app = express();
app.use(express.json());
const PORT = 8081;

const usersRouter=require("./routes/users.js")
const booksRouter=require("./routes/books.js")

app.get("/", (req, res) => {
  res.status(200).json({
    message: "Server is up and running",
  });
});

// https://localhost8081/users
app.use("/users",usersRouter)

// https://localhost8081/books
app.use("/books",booksRouter)

app.get("*", (req, res) => {
  res.status(200).json({
    message: "This route does not exit",
  });
});

app.listen(PORT, () => {
  console.log("Server is running on PORT:", PORT);
});
