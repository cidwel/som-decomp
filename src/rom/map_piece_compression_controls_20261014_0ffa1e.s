.setcpu "65816"
.segment "CODE"
.org $FA1E
map_control_0ffa1e:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
