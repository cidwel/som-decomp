.setcpu "65816"
.segment "CODE"
.org $CD97
map_control_0ecd97:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
