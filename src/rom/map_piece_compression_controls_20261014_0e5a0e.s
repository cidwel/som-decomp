.setcpu "65816"
.segment "CODE"
.org $5A0E
map_control_0e5a0e:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
