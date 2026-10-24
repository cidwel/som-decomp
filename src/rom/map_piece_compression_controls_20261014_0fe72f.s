.setcpu "65816"
.segment "CODE"
.org $E72F
map_control_0fe72f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
