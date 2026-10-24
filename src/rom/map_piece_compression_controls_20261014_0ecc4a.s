.setcpu "65816"
.segment "CODE"
.org $CC4A
map_control_0ecc4a:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
