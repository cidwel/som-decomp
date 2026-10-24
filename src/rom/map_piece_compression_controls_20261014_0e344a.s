.setcpu "65816"
.segment "CODE"
.org $344A
map_control_0e344a:
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
