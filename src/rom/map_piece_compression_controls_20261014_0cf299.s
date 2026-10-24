.setcpu "65816"
.segment "CODE"
.org $F299
map_control_0cf299:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
