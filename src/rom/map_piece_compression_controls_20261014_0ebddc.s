.setcpu "65816"
.segment "CODE"
.org $BDDC
map_control_0ebddc:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
