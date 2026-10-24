.setcpu "65816"
.segment "CODE"
.org $5FFF
map_control_0d5fff:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
