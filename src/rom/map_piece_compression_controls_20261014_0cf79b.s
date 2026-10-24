.setcpu "65816"
.segment "CODE"
.org $F79B
map_control_0cf79b:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
