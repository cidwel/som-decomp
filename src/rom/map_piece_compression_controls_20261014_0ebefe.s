.setcpu "65816"
.segment "CODE"
.org $BEFE
map_control_0ebefe:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
