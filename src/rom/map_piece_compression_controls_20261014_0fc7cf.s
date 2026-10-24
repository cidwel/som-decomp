.setcpu "65816"
.segment "CODE"
.org $C7CF
map_control_0fc7cf:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
