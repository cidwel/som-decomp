.setcpu "65816"
.segment "CODE"
.org $F4C0
map_control_0ef4c0:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
