.setcpu "65816"
.segment "CODE"
.org $C854
map_control_0fc854:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
