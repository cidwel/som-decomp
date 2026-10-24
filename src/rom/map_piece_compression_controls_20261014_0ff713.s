.setcpu "65816"
.segment "CODE"
.org $F713
map_control_0ff713:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
