.setcpu "65816"
.segment "CODE"
.org $DB11
map_control_0edb11:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
