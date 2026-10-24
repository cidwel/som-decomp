.setcpu "65816"
.segment "CODE"
.org $2EAF
map_control_0f2eaf:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
