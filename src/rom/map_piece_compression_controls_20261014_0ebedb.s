.setcpu "65816"
.segment "CODE"
.org $BEDB
map_control_0ebedb:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
