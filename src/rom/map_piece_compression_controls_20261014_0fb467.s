.setcpu "65816"
.segment "CODE"
.org $B467
map_control_0fb467:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
