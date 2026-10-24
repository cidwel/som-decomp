.setcpu "65816"
.segment "CODE"
.org $F7E7
map_control_0ff7e7:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
