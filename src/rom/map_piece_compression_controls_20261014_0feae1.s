.setcpu "65816"
.segment "CODE"
.org $EAE1
map_control_0feae1:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
