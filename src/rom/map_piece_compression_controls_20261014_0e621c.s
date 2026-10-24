.setcpu "65816"
.segment "CODE"
.org $621C
map_control_0e621c:
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
