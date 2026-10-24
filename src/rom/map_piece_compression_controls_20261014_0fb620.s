.setcpu "65816"
.segment "CODE"
.org $B620
map_control_0fb620:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
