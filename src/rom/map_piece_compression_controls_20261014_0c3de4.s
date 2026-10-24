.setcpu "65816"
.segment "CODE"
.org $3DE4
map_control_0c3de4:
    .byte $DB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
