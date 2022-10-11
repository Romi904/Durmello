import React from 'react'
import "./button.css";
import { useNavigate } from "react-router-dom";

const Button = () => {
  let navigate = useNavigate(); 
  const routeChange = () =>{ 
    let path = `home`; 
    navigate(path);
  }
  return (
    <div className="Name">
      <h1 className="text">Quiz App</h1>
      <a href="#" class="button" onClick={routeChange}>START</a>
    </div>
  )
}

export default Button
