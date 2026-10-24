.setcpu "65816"
.segment "CODE"
.org $155B
map_control_0f155b:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
