.setcpu "65816"
.segment "CODE"
.org $F357
map_control_0df357:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
