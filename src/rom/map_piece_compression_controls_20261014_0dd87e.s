.setcpu "65816"
.segment "CODE"
.org $D87E
map_control_0dd87e:
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
