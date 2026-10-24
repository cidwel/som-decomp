.setcpu "65816"
.segment "CODE"
.org $D78A
map_control_0dd78a:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
