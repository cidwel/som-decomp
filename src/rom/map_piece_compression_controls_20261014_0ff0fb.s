.setcpu "65816"
.segment "CODE"
.org $F0FB
map_control_0ff0fb:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
