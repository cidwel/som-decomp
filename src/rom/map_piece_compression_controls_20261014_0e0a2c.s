.setcpu "65816"
.segment "CODE"
.org $0A2C
map_control_0e0a2c:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
