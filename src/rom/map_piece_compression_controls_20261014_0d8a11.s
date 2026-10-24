.setcpu "65816"
.segment "CODE"
.org $8A11
map_control_0d8a11:
    .byte $E0 ; previous-row copy escape
    .byte $AA ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
