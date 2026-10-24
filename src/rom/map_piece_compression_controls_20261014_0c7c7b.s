.setcpu "65816"
.segment "CODE"
.org $7C7B
map_control_0c7c7b:
    .byte $C6 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
