.setcpu "65816"
.segment "CODE"
.org $33BA
map_control_0e33ba:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
