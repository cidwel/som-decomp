.setcpu "65816"
.segment "CODE"
.org $3CB4
map_control_0c3cb4:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
