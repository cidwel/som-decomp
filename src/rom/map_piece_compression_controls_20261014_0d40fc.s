.setcpu "65816"
.segment "CODE"
.org $40FC
map_control_0d40fc:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
