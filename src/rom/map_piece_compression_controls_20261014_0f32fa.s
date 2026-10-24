.setcpu "65816"
.segment "CODE"
.org $32FA
map_control_0f32fa:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
