.setcpu "65816"
.segment "CODE"
.org $B07A
map_control_0fb07a:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
