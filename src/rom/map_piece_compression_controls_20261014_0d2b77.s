.setcpu "65816"
.segment "CODE"
.org $2B77
map_control_0d2b77:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
