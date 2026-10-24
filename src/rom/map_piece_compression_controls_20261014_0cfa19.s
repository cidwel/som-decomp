.setcpu "65816"
.segment "CODE"
.org $FA19
map_control_0cfa19:
    .byte $E1 ; previous-row copy count
