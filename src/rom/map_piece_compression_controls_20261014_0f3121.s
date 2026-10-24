.setcpu "65816"
.segment "CODE"
.org $3121
map_control_0f3121:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
