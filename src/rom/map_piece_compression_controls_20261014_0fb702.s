.setcpu "65816"
.segment "CODE"
.org $B702
map_control_0fb702:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
