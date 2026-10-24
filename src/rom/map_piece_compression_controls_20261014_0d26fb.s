.setcpu "65816"
.segment "CODE"
.org $26FB
map_control_0d26fb:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
