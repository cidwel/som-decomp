.setcpu "65816"
.segment "CODE"
.org $13E7
map_control_0e13e7:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
