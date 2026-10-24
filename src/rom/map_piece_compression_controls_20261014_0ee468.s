.setcpu "65816"
.segment "CODE"
.org $E468
map_control_0ee468:
    .byte $F3 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
