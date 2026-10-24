.setcpu "65816"
.segment "CODE"
.org $2015
map_control_0f2015:
    .byte $E5 ; previous-row copy count
