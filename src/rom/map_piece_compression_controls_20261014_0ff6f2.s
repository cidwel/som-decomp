.setcpu "65816"
.segment "CODE"
.org $F6F2
map_control_0ff6f2:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
