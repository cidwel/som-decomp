.setcpu "65816"
.segment "CODE"
.org $F635
map_control_0ff635:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
