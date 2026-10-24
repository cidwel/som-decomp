.setcpu "65816"
.segment "CODE"
.org $9747
map_control_0f9747:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
