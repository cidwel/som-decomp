.setcpu "65816"
.segment "CODE"
.org $6714
map_control_0f6714:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $CD ; same-value copy count/distance
