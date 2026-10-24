.setcpu "65816"
.segment "CODE"
.org $6022
map_control_0d6022:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
