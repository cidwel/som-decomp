.setcpu "65816"
.segment "CODE"
.org $CE2B
map_control_0fce2b:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
