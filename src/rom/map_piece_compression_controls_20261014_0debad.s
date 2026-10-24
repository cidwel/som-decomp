.setcpu "65816"
.segment "CODE"
.org $EBAD
map_control_0debad:
    .byte $E8 ; backreference distance high bits
    .byte $5E ; distance low bit/count
