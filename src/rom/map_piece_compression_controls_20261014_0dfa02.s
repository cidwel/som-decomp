.setcpu "65816"
.segment "CODE"
.org $FA02
map_control_0dfa02:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
