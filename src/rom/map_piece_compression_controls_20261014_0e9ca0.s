.setcpu "65816"
.segment "CODE"
.org $9CA0
map_control_0e9ca0:
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
