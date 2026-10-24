.setcpu "65816"
.segment "CODE"
.org $35F0
map_control_0f35f0:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
