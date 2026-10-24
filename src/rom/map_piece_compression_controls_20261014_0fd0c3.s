.setcpu "65816"
.segment "CODE"
.org $D0C3
map_control_0fd0c3:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $70 ; row-distance/count
