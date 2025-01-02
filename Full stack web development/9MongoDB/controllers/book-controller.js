const {UserModel,BookModel}=require("../models/localIndex")
const IssuedBook = require("../dtos/book-dto")

// exports.getAllBooks=()=>{}
const getAllBooks=async (req,res)=>{
    const book=await BookModel.find()
    if(book.length==0){
        return res.status(404).json({
            success:false,
            message:"No book found"
        })
    }
    res.status(200).json({
        success:true,
        data:book,
    })
}
const getSingleBookById=async (req,res)=>{
    const {id}=req.params;
    const book=await BookModel.findById(id);
    if(!book){
        return res.status(404).json({
            success:false,
            message:"Book not found"
        })
    }
    res.status(200).json({
        success:true,
        data:book
    })
}

const getAllIssuedBooks=async (req,res)=>{
    const user=await UserModel.find({
        issuedBook:{$exists:true},
    }).populate("issuedBook")

    // Data transfer object 
    const issuedBooks=user.map((each)=>new IssuedBook(each))
    
    if(issuedBooks.length==0){
        return res.status(404).json({
            success:false,
            message:"No book have been issued"
        })
    }
    res.status(200).json({
        success:true,
        data:issuedBooks
    })
}

const addNewBook=async(req,res)=>{
    const data=req.body;
    if(!body){
        return res.status(404).json({
            success:false,
            message:"No data found"
        })
    }
    await BookModel.create(data)
    const allBooks=await BookModel.find()
    res.status(200).json({
        success:true,
        data:allBooks
    })
}

const updateBookById=async(req,res)=>{
    const id=req.params.id;
    const data=req.body;
    const updatedBook=await BookModel.findOneAndUpdate({_id:id},data,{new:true})

    res.status(200).json({
        success:true,
        data:updatedBook,
    })
}

module.exports={getAllBooks,getSingleBookById,getAllIssuedBooks,addNewBook,updateBookById}