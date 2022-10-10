import * as React from 'react';
import ReactDOM from 'react-dom';
import {
  BrowserRouter as Router,
  Routes,
  Route,
  Link
} from "react-router-dom";
import Button from './components/Button';
import Home from "./components/Home";
import "./index.css"

ReactDOM.render(
 
  <Router>
        
        <Routes>
          
          <Route exact path ="/" element={<Button/>}/>
          <Route path = "/home" element={<Home/>}/>
         
        </Routes>
        </Router>,
  
  document.querySelector("#root")
);