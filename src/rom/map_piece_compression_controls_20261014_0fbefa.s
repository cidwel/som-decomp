.setcpu "65816"
.segment "CODE"
.org $BEFA
map_control_0fbefa:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
