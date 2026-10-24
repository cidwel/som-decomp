.setcpu "65816"
.segment "CODE"
.org $1103
map_control_0c1103:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
