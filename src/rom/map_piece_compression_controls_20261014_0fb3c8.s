.setcpu "65816"
.segment "CODE"
.org $B3C8
map_control_0fb3c8:
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
