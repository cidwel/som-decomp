.setcpu "65816"
.segment "CODE"
.org $564B
map_control_0d564b:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $CA ; same-value copy count/distance
