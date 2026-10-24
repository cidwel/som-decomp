.setcpu "65816"
.segment "CODE"
.org $BA53
map_control_0eba53:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
