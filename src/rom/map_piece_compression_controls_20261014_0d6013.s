.setcpu "65816"
.segment "CODE"
.org $6013
map_control_0d6013:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
