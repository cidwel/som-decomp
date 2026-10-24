.setcpu "65816"
.segment "CODE"
.org $803D
map_control_0d803d:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
