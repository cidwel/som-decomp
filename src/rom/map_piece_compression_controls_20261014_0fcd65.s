.setcpu "65816"
.segment "CODE"
.org $CD65
map_control_0fcd65:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
