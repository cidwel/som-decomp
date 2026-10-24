.setcpu "65816"
.segment "CODE"
.org $DEB0
map_control_0edeb0:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
