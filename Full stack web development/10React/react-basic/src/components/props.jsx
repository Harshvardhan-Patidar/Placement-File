import React, { useState } from "react"

const Props=(props)=>{
    let {name,age}=props
    const [changeName,setName]=useState(name)
    const [updateName,setUpdateName]=useState("");
    return(
        <>
        <h1>My name: {changeName} <br /> age: {age}</h1>
        <h1>Name change By clicking: {updateName}</h1>
        <input onChange={(e)=>setName(e.target.value)}/>
        <button onClick={()=>setUpdateName(changeName)}>Click to change name</button>
        </>
    )
}

export default Props