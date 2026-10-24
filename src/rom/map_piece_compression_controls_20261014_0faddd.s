.setcpu "65816"
.segment "CODE"
.org $ADDD
map_control_0faddd:
    .byte $E3 ; previous-row copy count
