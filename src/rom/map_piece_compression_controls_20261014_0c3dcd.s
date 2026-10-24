.setcpu "65816"
.segment "CODE"
.org $3DCD
map_control_0c3dcd:
    .byte $DB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
