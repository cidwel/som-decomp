.setcpu "65816"
.segment "CODE"
.org $55CE
map_control_0f55ce:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
