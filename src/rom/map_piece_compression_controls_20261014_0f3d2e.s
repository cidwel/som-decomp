.setcpu "65816"
.segment "CODE"
.org $3D2E
map_control_0f3d2e:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
