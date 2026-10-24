.setcpu "65816"
.segment "CODE"
.org $093C
map_control_0d093c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
