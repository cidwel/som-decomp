.setcpu "65816"
.segment "CODE"
.org $402C
map_control_0f402c:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $52 ; distance low bit/count
