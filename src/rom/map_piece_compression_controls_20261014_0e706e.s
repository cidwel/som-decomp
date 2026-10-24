.setcpu "65816"
.segment "CODE"
.org $706E
map_control_0e706e:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
