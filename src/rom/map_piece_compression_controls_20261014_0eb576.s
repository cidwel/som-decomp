.setcpu "65816"
.segment "CODE"
.org $B576
map_control_0eb576:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
