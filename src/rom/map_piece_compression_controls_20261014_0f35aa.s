.setcpu "65816"
.segment "CODE"
.org $35AA
map_control_0f35aa:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
