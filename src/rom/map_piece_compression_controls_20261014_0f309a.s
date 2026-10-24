.setcpu "65816"
.segment "CODE"
.org $309A
map_control_0f309a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
