.setcpu "65816"
.segment "CODE"
.org $31D0
map_control_0d31d0:
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
