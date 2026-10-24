.setcpu "65816"
.segment "CODE"
.org $321B
map_control_0c321b:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
