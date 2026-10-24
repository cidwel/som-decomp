.setcpu "65816"
.segment "CODE"
.org $35DD
map_control_0f35dd:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
