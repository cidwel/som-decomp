.setcpu "65816"
.segment "CODE"
.org $1121
map_control_0c1121:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
