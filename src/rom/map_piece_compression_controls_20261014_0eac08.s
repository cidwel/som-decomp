.setcpu "65816"
.segment "CODE"
.org $AC08
map_control_0eac08:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $94 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
