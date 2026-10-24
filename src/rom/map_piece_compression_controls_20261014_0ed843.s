.setcpu "65816"
.segment "CODE"
.org $D843
map_control_0ed843:
    .byte $EB ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $44 ; distance low bit/count
