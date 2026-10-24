.setcpu "65816"
.segment "CODE"
.org $FFEC
map_control_0effec:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
