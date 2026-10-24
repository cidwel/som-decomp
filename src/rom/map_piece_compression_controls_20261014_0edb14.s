.setcpu "65816"
.segment "CODE"
.org $DB14
map_control_0edb14:
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
