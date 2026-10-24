.setcpu "65816"
.segment "CODE"
.org $592E
map_control_0d592e:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
