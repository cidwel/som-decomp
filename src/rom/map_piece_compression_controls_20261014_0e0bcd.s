.setcpu "65816"
.segment "CODE"
.org $0BCD
map_control_0e0bcd:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
