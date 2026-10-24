.setcpu "65816"
.segment "CODE"
.org $8FB3
map_control_0e8fb3:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
