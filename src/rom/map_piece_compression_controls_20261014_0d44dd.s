.setcpu "65816"
.segment "CODE"
.org $44DD
map_control_0d44dd:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
