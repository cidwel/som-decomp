.setcpu "65816"
.segment "CODE"
.org $4D12
map_control_0c4d12:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
