.setcpu "65816"
.segment "CODE"
.org $C93F
map_control_0ec93f:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
