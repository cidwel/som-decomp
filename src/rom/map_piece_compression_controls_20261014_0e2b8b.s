.setcpu "65816"
.segment "CODE"
.org $2B8B
map_control_0e2b8b:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
