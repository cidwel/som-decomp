.setcpu "65816"
.segment "CODE"
.org $AE34
map_control_0dae34:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
