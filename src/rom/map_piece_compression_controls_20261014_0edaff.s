.setcpu "65816"
.segment "CODE"
.org $DAFF
map_control_0edaff:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
