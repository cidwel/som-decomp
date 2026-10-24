.setcpu "65816"
.segment "CODE"
.org $C1BB
map_control_0fc1bb:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
