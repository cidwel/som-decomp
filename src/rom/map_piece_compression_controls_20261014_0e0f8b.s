.setcpu "65816"
.segment "CODE"
.org $0F8B
map_control_0e0f8b:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
