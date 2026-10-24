.setcpu "65816"
.segment "CODE"
.org $630F
map_control_0d630f:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
