.setcpu "65816"
.segment "CODE"
.org $B420
map_control_0eb420:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
