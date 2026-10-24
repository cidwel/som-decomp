.setcpu "65816"
.segment "CODE"
.org $23A6
map_control_0f23a6:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
