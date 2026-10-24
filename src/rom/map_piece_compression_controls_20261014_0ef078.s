.setcpu "65816"
.segment "CODE"
.org $F078
map_control_0ef078:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
