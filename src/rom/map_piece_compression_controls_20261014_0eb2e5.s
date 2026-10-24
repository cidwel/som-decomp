.setcpu "65816"
.segment "CODE"
.org $B2E5
map_control_0eb2e5:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
