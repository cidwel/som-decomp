.setcpu "65816"
.segment "CODE"
.org $09BD
map_control_0f09bd:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
