.setcpu "65816"
.segment "CODE"
.org $0912
map_control_0e0912:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
