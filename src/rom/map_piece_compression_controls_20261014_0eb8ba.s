.setcpu "65816"
.segment "CODE"
.org $B8BA
map_control_0eb8ba:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
