.setcpu "65816"
.segment "CODE"
.org $B0B7
map_control_0db0b7:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
