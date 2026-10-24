.setcpu "65816"
.segment "CODE"
.org $F8A6
map_control_0ef8a6:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
