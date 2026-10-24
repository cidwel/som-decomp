.setcpu "65816"
.segment "CODE"
.org $E8F0
map_control_0de8f0:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
