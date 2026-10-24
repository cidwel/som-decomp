.setcpu "65816"
.segment "CODE"
.org $BC7B
map_control_0fbc7b:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
