.setcpu "65816"
.segment "CODE"
.org $CD86
map_control_0ecd86:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
