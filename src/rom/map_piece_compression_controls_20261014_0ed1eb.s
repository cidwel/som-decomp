.setcpu "65816"
.segment "CODE"
.org $D1EB
map_control_0ed1eb:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
