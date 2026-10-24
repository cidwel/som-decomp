.setcpu "65816"
.segment "CODE"
.org $DB4E
map_control_0fdb4e:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
