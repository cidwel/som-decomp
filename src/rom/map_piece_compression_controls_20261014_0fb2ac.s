.setcpu "65816"
.segment "CODE"
.org $B2AC
map_control_0fb2ac:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
