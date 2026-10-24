.setcpu "65816"
.segment "CODE"
.org $CD82
map_control_0fcd82:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
