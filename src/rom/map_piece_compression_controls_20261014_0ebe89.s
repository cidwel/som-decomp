.setcpu "65816"
.segment "CODE"
.org $BE89
map_control_0ebe89:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
