.setcpu "65816"
.segment "CODE"
.org $99A5
map_control_0f99a5:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
