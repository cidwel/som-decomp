.setcpu "65816"
.segment "CODE"
.org $FE34
map_control_0efe34:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
