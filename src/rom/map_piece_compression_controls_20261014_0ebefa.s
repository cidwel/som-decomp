.setcpu "65816"
.segment "CODE"
.org $BEFA
map_control_0ebefa:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
