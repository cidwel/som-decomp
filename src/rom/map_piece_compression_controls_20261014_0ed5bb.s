.setcpu "65816"
.segment "CODE"
.org $D5BB
map_control_0ed5bb:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
