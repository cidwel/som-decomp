.setcpu "65816"
.segment "CODE"
.org $FC92
map_control_0efc92:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
