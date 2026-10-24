.setcpu "65816"
.segment "CODE"
.org $89E2
map_control_0f89e2:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
