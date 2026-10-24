.setcpu "65816"
.segment "CODE"
.org $106A
map_control_0c106a:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
