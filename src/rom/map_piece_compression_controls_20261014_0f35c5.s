.setcpu "65816"
.segment "CODE"
.org $35C5
map_control_0f35c5:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
