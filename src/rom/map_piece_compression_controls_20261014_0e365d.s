.setcpu "65816"
.segment "CODE"
.org $365D
map_control_0e365d:
    .byte $EB ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
