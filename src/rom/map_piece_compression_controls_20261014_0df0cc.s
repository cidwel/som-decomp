.setcpu "65816"
.segment "CODE"
.org $F0CC
map_control_0df0cc:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
