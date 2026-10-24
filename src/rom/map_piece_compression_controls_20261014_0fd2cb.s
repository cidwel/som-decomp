.setcpu "65816"
.segment "CODE"
.org $D2CB
map_control_0fd2cb:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
