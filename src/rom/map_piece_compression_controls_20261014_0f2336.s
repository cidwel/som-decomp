.setcpu "65816"
.segment "CODE"
.org $2336
map_control_0f2336:
    .byte $EA ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E3 ; previous-row copy count
