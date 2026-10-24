.setcpu "65816"
.segment "CODE"
.org $780E
map_control_0f780e:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
