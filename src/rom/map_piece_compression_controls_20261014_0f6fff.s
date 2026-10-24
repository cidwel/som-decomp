.setcpu "65816"
.segment "CODE"
.org $6FFF
map_control_0f6fff:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
