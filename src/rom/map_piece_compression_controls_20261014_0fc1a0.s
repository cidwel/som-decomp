.setcpu "65816"
.segment "CODE"
.org $C1A0
map_control_0fc1a0:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
