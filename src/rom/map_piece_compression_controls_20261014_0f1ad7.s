.setcpu "65816"
.segment "CODE"
.org $1AD7
map_control_0f1ad7:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
