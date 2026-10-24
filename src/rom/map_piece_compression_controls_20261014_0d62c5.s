.setcpu "65816"
.segment "CODE"
.org $62C5
map_control_0d62c5:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
