.setcpu "65816"
.segment "CODE"
.org $4AAD
map_control_0e4aad:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
