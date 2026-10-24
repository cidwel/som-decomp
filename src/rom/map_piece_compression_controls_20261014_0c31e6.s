.setcpu "65816"
.segment "CODE"
.org $31E6
map_control_0c31e6:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
