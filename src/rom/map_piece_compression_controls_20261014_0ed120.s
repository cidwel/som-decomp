.setcpu "65816"
.segment "CODE"
.org $D120
map_control_0ed120:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
