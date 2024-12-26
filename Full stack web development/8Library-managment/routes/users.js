const express=require("express")
const router=express.Router()
const { users } = require("../data/users.json");

// method: get
// route: /users
router.get("/", (req, res) => {
    res.status(200).json({
      success: true,
      data: users,
    });
  });
  
  // route: /users/:id
  router.get("/:id", (req, res) => {
    const { id } = req.params;
    const user = users.find((iterate) => iterate.id == id);
    if (!user) {
      return res.status(404).json({
        success: false,
        message: "User not found",
      });
    }
    res.status(200).json({
      success: true,
      user,
    });
  });

// method: post
// route: /users
router.post("/", (req, res) => {
    const {
      id,
      name,
      surname,
      email,
      issuedBook,
      issuedDate,
      subscriptionType,
      subscriptionDate,
    } = req.body;
    const user = users.find((iterate) => (iterate.id = id));
    if (user) {
      return res.status(404).json({
        success: false,
        message: "User already found",
      });
    }
  
    users.push({
      id,
      name,
      surname,
      email,
      issuedBook,
      issuedDate,
      subscriptionType,
      subscriptionDate,
    });
  
    res.status(201).json({
      success: true,
      message: "User added",
    });
  });

// method: put
// route: /users/:id (updating the data)
router.put("/:id", (req, res) => {
    const id = req.params;
    const data = req.body;
    const user = users.find((iterate) => users.id == id);
    if (!user) {
      return res.status(404).json({
        success: false,
        message: "User not found",
      });
    }
  
    const updateUserData = users.map((iterate) => {
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
  
  // method: delete
  // route: /users/:id
  router.delete("/:id",(req,res)=>{
    const id=req.params;
    const user=users.find((iterate)=>iterate.id==id);
    if(!user){
      return res.status(404).json({
        success:true,
        message:"User not found",
      })
    }
  
    const index=users.indexOf(user);
    users.splice(index,1);
    res.status(200).json({
      success:true,
      message:"User deleted",
    })
  })

module.exports=router;