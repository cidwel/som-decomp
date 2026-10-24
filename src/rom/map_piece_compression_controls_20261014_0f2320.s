.setcpu "65816"
.segment "CODE"
.org $2320
map_control_0f2320:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
