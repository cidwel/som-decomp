.setcpu "65816"
.segment "CODE"
.org $A18F
map_control_0fa18f:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
