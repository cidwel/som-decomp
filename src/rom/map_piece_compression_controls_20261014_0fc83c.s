.setcpu "65816"
.segment "CODE"
.org $C83C
map_control_0fc83c:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
