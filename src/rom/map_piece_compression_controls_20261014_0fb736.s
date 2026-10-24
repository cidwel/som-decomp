.setcpu "65816"
.segment "CODE"
.org $B736
map_control_0fb736:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
