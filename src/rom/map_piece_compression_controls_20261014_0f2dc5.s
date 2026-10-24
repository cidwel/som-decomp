.setcpu "65816"
.segment "CODE"
.org $2DC5
map_control_0f2dc5:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
