.setcpu "65816"
.segment "CODE"
.org $96F1
map_control_0e96f1:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
