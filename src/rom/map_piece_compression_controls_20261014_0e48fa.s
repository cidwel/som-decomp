.setcpu "65816"
.segment "CODE"
.org $48FA
map_control_0e48fa:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
