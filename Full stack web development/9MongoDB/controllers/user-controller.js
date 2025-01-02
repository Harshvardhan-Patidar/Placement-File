
const {UserModel,BookModel}=require("../models/localIndex")

const getAllUsers=async (req,res)=>{
    const user=await UserModel.find()
    if(!user){
        return res.status(404).json({
            success:false,
            message:"No user found"
        })
    }
    res.status(200).json({
        success:true,
        user,
    })
}

const updateUserData=async(req,res)=>{
    const {id}=req.params;
    const {data}=req.body;
    const updateUser=await UserModel.findOneAndUpdate({_id:id},{$set:{...data}},{new:true})
    res.status(200).json({
        success:true,
        message:"User Data updated"
    })
}

module.exports={getAllUsers,updateUserData}