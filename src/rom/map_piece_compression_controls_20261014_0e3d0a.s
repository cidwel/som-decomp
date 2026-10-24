.setcpu "65816"
.segment "CODE"
.org $3D0A
map_control_0e3d0a:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
