.setcpu "65816"
.segment "CODE"
.org $304B
map_control_0f304b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
