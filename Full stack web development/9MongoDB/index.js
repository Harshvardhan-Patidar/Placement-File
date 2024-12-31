const dotenv=require("dotenv");
const dbConnection=require("./DBconnection.js")

const express=require("express")
const app=express();
app.use(express.json)
const PORT=5173;

dotenv.config();
dbConnection();

app.get("/",(req,res)=>{
    res.status(200).json({
        message:"Server is up and running"
    })
})

const usersRouter=require("./routes/users.js")
const booksRouter=require("./routes/books.js")
app.use("/users",usersRouter)
app.use("/books",booksRouter)

app.get("*",(req,res)=>{
    res.status(200).json({
        message:"This route does not exixt"
    })
})

app.listen(PORT,()=>{
    console.log("Server is running on PORT:",PORT)
})
