.setcpu "65816"
.segment "CODE"
.org $19DD
map_control_0c19dd:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
