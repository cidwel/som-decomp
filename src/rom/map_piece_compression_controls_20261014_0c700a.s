.setcpu "65816"
.segment "CODE"
.org $700A
map_control_0c700a:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
