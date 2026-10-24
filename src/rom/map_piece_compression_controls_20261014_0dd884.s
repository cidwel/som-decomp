.setcpu "65816"
.segment "CODE"
.org $D884
map_control_0dd884:
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
