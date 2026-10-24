.setcpu "65816"
.segment "CODE"
.org $78A3
map_control_0d78a3:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
