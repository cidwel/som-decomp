.setcpu "65816"
.segment "CODE"
.org $393C
map_control_0e393c:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
