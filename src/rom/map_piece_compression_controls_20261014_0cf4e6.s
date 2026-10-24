.setcpu "65816"
.segment "CODE"
.org $F4E6
map_control_0cf4e6:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
