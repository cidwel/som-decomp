.setcpu "65816"
.segment "CODE"
.org $AFA9
map_control_0fafa9:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
