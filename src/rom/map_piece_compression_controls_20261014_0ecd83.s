.setcpu "65816"
.segment "CODE"
.org $CD83
map_control_0ecd83:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
