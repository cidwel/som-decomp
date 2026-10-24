.setcpu "65816"
.segment "CODE"
.org $E590
map_control_0fe590:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
