.setcpu "65816"
.segment "CODE"
.org $F59A
map_control_0df59a:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
