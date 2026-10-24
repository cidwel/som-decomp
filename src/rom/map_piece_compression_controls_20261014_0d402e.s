.setcpu "65816"
.segment "CODE"
.org $402E
map_control_0d402e:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
