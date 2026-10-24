.setcpu "65816"
.segment "CODE"
.org $BE0D
map_control_0ebe0d:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
