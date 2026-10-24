.setcpu "65816"
.segment "CODE"
.org $B9E6
map_control_0eb9e6:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
