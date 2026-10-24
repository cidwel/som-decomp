.setcpu "65816"
.segment "CODE"
.org $AC2A
map_control_0eac2a:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $8E ; distance low bit/count
