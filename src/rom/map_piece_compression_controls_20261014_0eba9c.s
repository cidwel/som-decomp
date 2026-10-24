.setcpu "65816"
.segment "CODE"
.org $BA9C
map_control_0eba9c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
