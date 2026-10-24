.setcpu "65816"
.segment "CODE"
.org $6A82
map_control_0f6a82:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
