.setcpu "65816"
.segment "CODE"
.org $DC2B
map_control_0fdc2b:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
