.setcpu "65816"
.segment "CODE"
.org $295B
map_control_0d295b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
