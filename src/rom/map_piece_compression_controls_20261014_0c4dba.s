.setcpu "65816"
.segment "CODE"
.org $4DBA
map_control_0c4dba:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
