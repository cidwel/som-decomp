.setcpu "65816"
.segment "CODE"
.org $35ED
map_control_0e35ed:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
