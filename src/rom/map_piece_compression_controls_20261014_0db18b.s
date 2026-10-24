.setcpu "65816"
.segment "CODE"
.org $B18B
map_control_0db18b:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $F1 ; progressive-copy count
