.setcpu "65816"
.segment "CODE"
.org $209F
map_control_0c209f:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
