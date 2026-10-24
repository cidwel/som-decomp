.setcpu "65816"
.segment "CODE"
.org $2863
map_control_0d2863:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
