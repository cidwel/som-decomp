.setcpu "65816"
.segment "CODE"
.org $62C0
map_control_0d62c0:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
