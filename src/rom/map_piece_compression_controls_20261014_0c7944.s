.setcpu "65816"
.segment "CODE"
.org $7944
map_control_0c7944:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
