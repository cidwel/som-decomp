.setcpu "65816"
.segment "CODE"
.org $305B
map_control_0f305b:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
