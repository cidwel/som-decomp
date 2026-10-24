.setcpu "65816"
.segment "CODE"
.org $89B7
map_control_0f89b7:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
