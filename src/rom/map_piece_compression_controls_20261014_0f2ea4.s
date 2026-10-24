.setcpu "65816"
.segment "CODE"
.org $2EA4
map_control_0f2ea4:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
