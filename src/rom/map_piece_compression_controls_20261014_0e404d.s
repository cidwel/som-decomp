.setcpu "65816"
.segment "CODE"
.org $404D
map_control_0e404d:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
