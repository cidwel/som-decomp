.setcpu "65816"
.segment "CODE"
.org $DBA2
map_control_0fdba2:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
