.setcpu "65816"
.segment "CODE"
.org $3D6C
map_control_0f3d6c:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
