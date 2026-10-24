.setcpu "65816"
.segment "CODE"
.org $94A8
map_control_0d94a8:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
