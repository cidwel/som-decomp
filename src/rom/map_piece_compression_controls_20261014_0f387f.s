.setcpu "65816"
.segment "CODE"
.org $387F
map_control_0f387f:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
