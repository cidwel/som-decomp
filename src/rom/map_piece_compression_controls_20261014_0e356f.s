.setcpu "65816"
.segment "CODE"
.org $356F
map_control_0e356f:
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
