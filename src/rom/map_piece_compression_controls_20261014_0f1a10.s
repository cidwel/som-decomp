.setcpu "65816"
.segment "CODE"
.org $1A10
map_control_0f1a10:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
