.setcpu "65816"
.segment "CODE"
.org $96BE
map_control_0f96be:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
