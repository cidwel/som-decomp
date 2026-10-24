.setcpu "65816"
.segment "CODE"
.org $B6C8
map_control_0fb6c8:
    .byte $E0 ; previous-row copy escape
    .byte $62 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2B ; distance low bit/count
