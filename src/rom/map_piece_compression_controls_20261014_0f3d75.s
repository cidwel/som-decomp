.setcpu "65816"
.segment "CODE"
.org $3D75
map_control_0f3d75:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
