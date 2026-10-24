.setcpu "65816"
.segment "CODE"
.org $0822
map_control_0e0822:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
