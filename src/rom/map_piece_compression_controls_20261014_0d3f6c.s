.setcpu "65816"
.segment "CODE"
.org $3F6C
map_control_0d3f6c:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
