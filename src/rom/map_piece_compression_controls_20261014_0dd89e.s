.setcpu "65816"
.segment "CODE"
.org $D89E
map_control_0dd89e:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
