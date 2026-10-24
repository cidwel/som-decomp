.setcpu "65816"
.segment "CODE"
.org $C881
map_control_0fc881:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
