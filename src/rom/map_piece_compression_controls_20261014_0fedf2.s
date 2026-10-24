.setcpu "65816"
.segment "CODE"
.org $EDF2
map_control_0fedf2:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
