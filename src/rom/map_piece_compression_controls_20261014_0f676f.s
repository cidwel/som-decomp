.setcpu "65816"
.segment "CODE"
.org $676F
map_control_0f676f:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
