.setcpu "65816"
.segment "CODE"
.org $2EC1
map_control_0f2ec1:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
