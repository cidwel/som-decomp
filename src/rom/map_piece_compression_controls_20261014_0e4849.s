.setcpu "65816"
.segment "CODE"
.org $4849
map_control_0e4849:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
