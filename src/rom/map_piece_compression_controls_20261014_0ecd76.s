.setcpu "65816"
.segment "CODE"
.org $CD76
map_control_0ecd76:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
