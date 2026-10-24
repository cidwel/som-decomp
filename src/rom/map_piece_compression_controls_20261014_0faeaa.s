.setcpu "65816"
.segment "CODE"
.org $AEAA
map_control_0faeaa:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
