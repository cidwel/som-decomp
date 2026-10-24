.setcpu "65816"
.segment "CODE"
.org $31B2
map_control_0e31b2:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
