.setcpu "65816"
.segment "CODE"
.org $886F
map_control_0e886f:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
