.setcpu "65816"
.segment "CODE"
.org $DD71
map_control_0edd71:
    .byte $ED ; backreference distance high bits
    .byte $96 ; distance low bit/count
