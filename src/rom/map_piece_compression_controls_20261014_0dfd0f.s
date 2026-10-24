.setcpu "65816"
.segment "CODE"
.org $FD0F
map_control_0dfd0f:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
