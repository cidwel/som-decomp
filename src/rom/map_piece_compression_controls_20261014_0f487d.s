.setcpu "65816"
.segment "CODE"
.org $487D
map_control_0f487d:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $F2 ; progressive-copy count
