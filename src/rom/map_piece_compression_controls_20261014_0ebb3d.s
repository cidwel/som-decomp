.setcpu "65816"
.segment "CODE"
.org $BB3D
map_control_0ebb3d:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
