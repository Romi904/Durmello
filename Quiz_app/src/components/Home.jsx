import Axios from 'axios';
import React, {useState, useEffect} from 'react';
import './home.css';
import Header from  "./Header";

const API_URL = "https://opentdb.com/api.php?amount=10&&type=multiple";

function App() {

  const [questions, setQuestions] = useState([]);
  const [Index1, setIndex1] = useState(0);
  const [score, setScore] = useState(0);
  const [showAnswers, setShowAnswers] = useState(false);

  useEffect(() =>{
    Axios.get(API_URL)
      .then(res => res.data)
      .then(data => {
        const questions = data.results.map((question) => ({
          ...question,
          answers:[question.correct_answer, ...question.incorrect_answers].sort(() => Math.random() - 0.5)
        }))
        setQuestions(questions)
      });
  },[])


  const handleAnswer = (answer) => {
    if(!showAnswers){
      if(answer === questions[Index1].correct_answer){
        setScore(score+1);
      }
    }
    

    setShowAnswers(true);
    
  }

  const nextQuestion = () => {
    setIndex1(Index1+1);
    setShowAnswers(false);
  }


  return ( questions.length > 0 ? (

    <div className="div1">
      {Index1 >= questions.length ? (
      <h1>Game Ended, Your Score is {score}<br/> Precentage  Secured {score * 10}% </h1> ): (<Header  handleAnswer={handleAnswer}
        showAnswers={showAnswers}
        nextQuestion={nextQuestion}
        data={questions[Index1]}/>)}
      
    </div>

  ) : <div className="div1">Loading...</div>
    
  );
}

export default App;