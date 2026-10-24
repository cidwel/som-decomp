.setcpu "65816"
.segment "CODE"
.org $C6D6
map_control_0dc6d6:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
