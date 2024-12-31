const {UserModel,BookModel}=require("../models/localIndex")

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
    const id=req.params;
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

exports.getAllIssuedBooks=async (req,res)=>{
    const user=await UserModel.find({
        issuedBook:{$exists:true},
    }).populate("issuedBook")
    
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

module.exports={getAllBooks,getSingleBookById}