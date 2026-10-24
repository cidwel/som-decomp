.setcpu "65816"
.segment "CODE"
.org $F4E4
map_control_0ef4e4:
    .byte $E0 ; previous-row copy escape
    .byte $B0 ; row-distance/count
