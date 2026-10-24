.setcpu "65816"
.segment "CODE"
.org $BC26
map_control_0ebc26:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
