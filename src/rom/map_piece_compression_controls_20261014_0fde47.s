.setcpu "65816"
.segment "CODE"
.org $DE47
map_control_0fde47:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
