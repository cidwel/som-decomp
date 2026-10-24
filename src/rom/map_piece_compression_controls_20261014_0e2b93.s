.setcpu "65816"
.segment "CODE"
.org $2B93
map_control_0e2b93:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
