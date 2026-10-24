.setcpu "65816"
.segment "CODE"
.org $B225
map_control_0fb225:
    .byte $E9 ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
