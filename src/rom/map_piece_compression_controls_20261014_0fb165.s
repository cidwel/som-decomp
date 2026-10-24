.setcpu "65816"
.segment "CODE"
.org $B165
map_control_0fb165:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
