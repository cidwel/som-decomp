.setcpu "65816"
.segment "CODE"
.org $BE9C
map_control_0fbe9c:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
