.setcpu "65816"
.segment "CODE"
.org $8074
map_control_0f8074:
    .byte $DB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
