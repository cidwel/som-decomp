.setcpu "65816"
.segment "CODE"
.org $75CC
map_control_0e75cc:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
