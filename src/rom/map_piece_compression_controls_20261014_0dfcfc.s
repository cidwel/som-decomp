.setcpu "65816"
.segment "CODE"
.org $FCFC
map_control_0dfcfc:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
