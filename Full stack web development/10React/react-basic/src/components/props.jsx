import React, { useState } from "react"

const Props=(props)=>{
    let {name,age}=props
    const [changeName,setName]=useState(name)
    return(
        <>
        <h1>My name: {changeName} <br /> age: {age}</h1>
        <input onChange={(e)=>setName(e.target.value)}/>
        </>
    )
}

export default Props