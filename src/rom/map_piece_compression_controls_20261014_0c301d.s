.setcpu "65816"
.segment "CODE"
.org $301D
map_control_0c301d:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
