.setcpu "65816"
.segment "CODE"
.org $EFDD
map_control_0eefdd:
    .byte $E1 ; previous-row copy count
