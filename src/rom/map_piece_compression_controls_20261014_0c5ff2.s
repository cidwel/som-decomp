.setcpu "65816"
.segment "CODE"
.org $5FF2
map_control_0c5ff2:
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
