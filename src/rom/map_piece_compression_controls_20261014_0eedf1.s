.setcpu "65816"
.segment "CODE"
.org $EDF1
map_control_0eedf1:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
