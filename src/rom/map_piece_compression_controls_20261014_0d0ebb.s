.setcpu "65816"
.segment "CODE"
.org $0EBB
map_control_0d0ebb:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
