.setcpu "65816"
.segment "CODE"
.org $3512
map_control_0e3512:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
