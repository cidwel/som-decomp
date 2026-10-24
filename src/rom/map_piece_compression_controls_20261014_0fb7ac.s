.setcpu "65816"
.segment "CODE"
.org $B7AC
map_control_0fb7ac:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
