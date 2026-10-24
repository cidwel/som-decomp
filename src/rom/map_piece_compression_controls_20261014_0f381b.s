.setcpu "65816"
.segment "CODE"
.org $381B
map_control_0f381b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
