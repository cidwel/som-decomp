.setcpu "65816"
.segment "CODE"
.org $6DE3
map_control_0c6de3:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
