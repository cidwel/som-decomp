.setcpu "65816"
.segment "CODE"
.org $1F95
map_control_0e1f95:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
