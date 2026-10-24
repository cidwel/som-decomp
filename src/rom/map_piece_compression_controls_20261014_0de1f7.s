.setcpu "65816"
.segment "CODE"
.org $E1F7
map_control_0de1f7:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
