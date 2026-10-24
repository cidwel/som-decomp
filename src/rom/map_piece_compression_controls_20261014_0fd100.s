.setcpu "65816"
.segment "CODE"
.org $D100
map_control_0fd100:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
