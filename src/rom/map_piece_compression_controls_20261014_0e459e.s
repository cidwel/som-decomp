.setcpu "65816"
.segment "CODE"
.org $459E
map_control_0e459e:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $D1 ; same-value copy count/distance
