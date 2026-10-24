.setcpu "65816"
.segment "CODE"
.org $6F32
map_control_0f6f32:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
