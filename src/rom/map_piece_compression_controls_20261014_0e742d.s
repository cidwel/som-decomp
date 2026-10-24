.setcpu "65816"
.segment "CODE"
.org $742D
map_control_0e742d:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
