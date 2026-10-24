.setcpu "65816"
.segment "CODE"
.org $40D0
map_control_0d40d0:
    .byte $DB ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
