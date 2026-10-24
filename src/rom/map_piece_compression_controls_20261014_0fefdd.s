.setcpu "65816"
.segment "CODE"
.org $EFDD
map_control_0fefdd:
    .byte $E4 ; previous-row copy count
