.setcpu "65816"
.segment "CODE"
.org $96AF
map_control_0e96af:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
