.setcpu "65816"
.segment "CODE"
.org $BD97
map_control_0dbd97:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
