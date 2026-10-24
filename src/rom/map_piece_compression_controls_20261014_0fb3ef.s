.setcpu "65816"
.segment "CODE"
.org $B3EF
map_control_0fb3ef:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
