.setcpu "65816"
.segment "CODE"
.org $2F4B
map_control_0f2f4b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
