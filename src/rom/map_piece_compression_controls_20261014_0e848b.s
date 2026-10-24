.setcpu "65816"
.segment "CODE"
.org $848B
map_control_0e848b:
    .byte $D4 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
