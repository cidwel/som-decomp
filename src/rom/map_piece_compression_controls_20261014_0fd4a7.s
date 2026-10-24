.setcpu "65816"
.segment "CODE"
.org $D4A7
map_control_0fd4a7:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
