<?php
    $waiting_day = 1637210196;
    $time_left = $waiting_day - time();

    $days = floor($time_left / (60*60*24));
    $time_left %= (60 * 60 * 24);

    $hours = floor($time_left / (60 * 60));
    $time_left %= (60 * 60);

    $min = floor($time_left / 60);
    $time_left %= 60;

    $sec = $time_left;

    echo "Remaing time: $days days and $hours hours and $min min and $sec sec left";
?>