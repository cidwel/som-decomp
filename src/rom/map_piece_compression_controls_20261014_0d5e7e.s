.setcpu "65816"
.segment "CODE"
.org $5E7E
map_control_0d5e7e:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
