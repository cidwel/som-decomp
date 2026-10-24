.setcpu "65816"
.segment "CODE"
.org $AD26
map_control_0ead26:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
