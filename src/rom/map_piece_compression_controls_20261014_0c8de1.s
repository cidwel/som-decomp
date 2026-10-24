.setcpu "65816"
.segment "CODE"
.org $8DE1
map_control_0c8de1:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
