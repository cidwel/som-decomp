.setcpu "65816"
.segment "CODE"
.org $CFAB
map_control_0ecfab:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
