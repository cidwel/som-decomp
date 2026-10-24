.setcpu "65816"
.segment "CODE"
.org $0D0B
map_control_0f0d0b:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E4 ; previous-row copy count
