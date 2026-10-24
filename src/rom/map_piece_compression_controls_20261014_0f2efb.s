.setcpu "65816"
.segment "CODE"
.org $2EFB
map_control_0f2efb:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
