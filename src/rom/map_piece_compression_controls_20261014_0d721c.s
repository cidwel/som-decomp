.setcpu "65816"
.segment "CODE"
.org $721C
map_control_0d721c:
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
