.setcpu "65816"
.segment "CODE"
.org $445E
map_control_0e445e:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
