.setcpu "65816"
.segment "CODE"
.org $1667
map_control_0c1667:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
