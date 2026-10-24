.setcpu "65816"
.segment "CODE"
.org $8CD6
map_control_0c8cd6:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $F1 ; progressive-copy count
