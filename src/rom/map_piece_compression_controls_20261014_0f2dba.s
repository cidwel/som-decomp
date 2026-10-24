.setcpu "65816"
.segment "CODE"
.org $2DBA
map_control_0f2dba:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
