.setcpu "65816"
.segment "CODE"
.org $C5F7
map_control_0fc5f7:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
