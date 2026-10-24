.setcpu "65816"
.segment "CODE"
.org $4F32
map_control_0f4f32:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
