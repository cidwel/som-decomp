.setcpu "65816"
.segment "CODE"
.org $B58E
map_control_0eb58e:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
