.setcpu "65816"
.segment "CODE"
.org $D61C
map_control_0dd61c:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
