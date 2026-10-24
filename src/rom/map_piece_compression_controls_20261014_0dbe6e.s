.setcpu "65816"
.segment "CODE"
.org $BE6E
map_control_0dbe6e:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
