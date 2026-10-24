.setcpu "65816"
.segment "CODE"
.org $2280
map_control_0f2280:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E2 ; previous-row copy count
