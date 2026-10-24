.setcpu "65816"
.segment "CODE"
.org $427B
map_control_0d427b:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
