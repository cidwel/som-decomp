.setcpu "65816"
.segment "CODE"
.org $BE7D
map_control_0ebe7d:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
