.setcpu "65816"
.segment "CODE"
.org $65C4
map_control_0c65c4:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E2 ; previous-row copy count
