.setcpu "65816"
.segment "CODE"
.org $F54B
map_control_0ef54b:
    .byte $E0 ; previous-row copy escape
    .byte $B5 ; row-distance/count
