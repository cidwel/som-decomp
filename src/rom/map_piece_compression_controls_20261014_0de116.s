.setcpu "65816"
.segment "CODE"
.org $E116
map_control_0de116:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
