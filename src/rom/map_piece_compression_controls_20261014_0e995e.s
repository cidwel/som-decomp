.setcpu "65816"
.segment "CODE"
.org $995E
map_control_0e995e:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
