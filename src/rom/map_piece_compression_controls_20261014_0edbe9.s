.setcpu "65816"
.segment "CODE"
.org $DBE9
map_control_0edbe9:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
