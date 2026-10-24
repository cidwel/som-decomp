.setcpu "65816"
.segment "CODE"
.org $41A5
map_control_0c41a5:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
