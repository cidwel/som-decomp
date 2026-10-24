.setcpu "65816"
.segment "CODE"
.org $EECF
map_control_0deecf:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
