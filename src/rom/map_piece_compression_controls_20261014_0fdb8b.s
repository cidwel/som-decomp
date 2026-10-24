.setcpu "65816"
.segment "CODE"
.org $DB8B
map_control_0fdb8b:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
