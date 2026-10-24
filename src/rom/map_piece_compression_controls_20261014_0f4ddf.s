.setcpu "65816"
.segment "CODE"
.org $4DDF
map_control_0f4ddf:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
