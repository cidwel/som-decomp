.setcpu "65816"
.segment "CODE"
.org $F3F5
map_control_0ef3f5:
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $B0 ; row-distance/count
