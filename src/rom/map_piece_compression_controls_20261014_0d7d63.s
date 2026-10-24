.setcpu "65816"
.segment "CODE"
.org $7D63
map_control_0d7d63:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E1 ; previous-row copy count
