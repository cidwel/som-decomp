.setcpu "65816"
.segment "CODE"
.org $6EFE
map_control_0e6efe:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
