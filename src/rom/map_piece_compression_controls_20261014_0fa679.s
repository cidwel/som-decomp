.setcpu "65816"
.segment "CODE"
.org $A679
map_control_0fa679:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
