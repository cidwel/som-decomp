.setcpu "65816"
.segment "CODE"
.org $31B6
map_control_0e31b6:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
