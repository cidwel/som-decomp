.setcpu "65816"
.segment "CODE"
.org $AEFA
map_control_0eaefa:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
