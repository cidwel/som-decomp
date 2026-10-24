.setcpu "65816"
.segment "CODE"
.org $B0B2
map_control_0fb0b2:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
