.setcpu "65816"
.segment "CODE"
.org $4B5F
map_control_0f4b5f:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E7 ; previous-row copy count
