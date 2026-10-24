.setcpu "65816"
.segment "CODE"
.org $95EB
map_control_0d95eb:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
