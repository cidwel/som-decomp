.setcpu "65816"
.segment "CODE"
.org $2C53
map_control_0f2c53:
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
