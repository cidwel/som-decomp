.setcpu "65816"
.segment "CODE"
.org $2296
map_control_0d2296:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
