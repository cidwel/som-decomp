.setcpu "65816"
.segment "CODE"
.org $4839
map_control_0d4839:
    .byte $E8 ; backreference distance high bits
    .byte $9E ; distance low bit/count
