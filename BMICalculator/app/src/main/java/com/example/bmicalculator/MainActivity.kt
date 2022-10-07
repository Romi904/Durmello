
package com.example.bmicalculator

import android.os.Bundle
import android.view.View
import android.widget.*
import androidx.appcompat.app.AppCompatActivity
import androidx.cardview.widget.CardView
import androidx.core.content.ContextCompat

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val weightInput=findViewById<EditText>(R.id.etWeight)
        val heightInput=findViewById<EditText>(R.id.etHeight)
        val calculateBtn=findViewById<Button>(R.id.btnCalculate)
        calculateBtn.setOnClickListener{
            val weight=weightInput.text.toString()
            val height=heightInput.text.toString()
            if(check(weight,height)) {
                val bmi = (weight.toFloat()) / ((height.toFloat() / 100) * (height.toFloat() / 100))
                val bmi2digit = String.format("%.2f", bmi).toFloat()
//             make the image indivisible
                val image=findViewById<ImageView>(R.id.imageView_logo)
                image.visibility= View.INVISIBLE

                display(bmi2digit)
            }
        }
    }
    private fun check(Weight:String?,Height:String?): Boolean {
        return when{
            Weight.isNullOrEmpty()->
            {
                Toast.makeText(this, "Weight section is Empty !", Toast.LENGTH_LONG).show()
                return false
            }
            Height.isNullOrEmpty()->{
                Toast.makeText(this, "Height section is Empty !", Toast.LENGTH_LONG).show()
                return  false
            }

            else -> {
                return true

            }
        }
    }
    private fun display(bmi:Float)
    {

        val cardView=findViewById<CardView>(R.id.ResultView)
        cardView.visibility=View.VISIBLE
        val bmiTextView=findViewById<TextView>(R.id.bmiResult)
        val bmiDescription=findViewById<TextView>(R.id.HealthDetails)
        val setImage=findViewById<ImageView>(R.id.imageView)
        val info=findViewById<TextView>(R.id.rangeOfWeight)
        info.text="[Normal range is 18.5 – 24.9] "
        var resultText=""
        var color=0
        when
        {
            bmi<=18.5->{
                resultText="UnderWeight"
                color= R.color.UnderWeight
                setImage.setImageResource(R.drawable.underweight)
            }
            bmi in 18.5..24.9->{
                resultText="Healthy"
                color= R.color.Healthy
                setImage.setImageResource(R.drawable.healthyweight)
            }
            bmi in 25.0..29.9->
            {
                resultText="OverWeight"
                color= R.color.Overweight
                setImage.setImageResource(R.drawable.overweight)
            }
            bmi>=30.0->{
                resultText="Obesity"
                color= R.color.Obesity
                setImage.setImageResource(R.drawable.obesweight)
            }
        }
        bmiTextView.text= "BMI Rate = $bmi"
        bmiDescription.text=resultText
        bmiDescription.setTextColor(ContextCompat.getColor(this,color))
    }
}