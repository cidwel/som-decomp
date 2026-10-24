.setcpu "65816"
.segment "CODE"
.org $C051
map_control_0fc051:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
