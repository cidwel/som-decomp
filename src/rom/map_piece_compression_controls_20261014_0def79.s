.setcpu "65816"
.segment "CODE"
.org $EF79
map_control_0def79:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
