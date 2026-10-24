.setcpu "65816"
.segment "CODE"
.org $ACE0
map_control_0dace0:
    .byte $E8 ; backreference distance high bits
    .byte $3D ; distance low bit/count
