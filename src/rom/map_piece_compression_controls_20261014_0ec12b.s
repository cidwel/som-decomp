.setcpu "65816"
.segment "CODE"
.org $C12B
map_control_0ec12b:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
