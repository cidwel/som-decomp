.setcpu "65816"
.segment "CODE"
.org $DBA0
map_control_0edba0:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
