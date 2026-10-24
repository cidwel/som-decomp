.setcpu "65816"
.segment "CODE"
.org $F4AB
map_control_0ef4ab:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
