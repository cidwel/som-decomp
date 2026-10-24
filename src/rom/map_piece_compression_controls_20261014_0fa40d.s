.setcpu "65816"
.segment "CODE"
.org $A40D
map_control_0fa40d:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $DB ; same-value copy count/distance
