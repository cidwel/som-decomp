.setcpu "65816"
.segment "CODE"
.org $5047
map_control_0c5047:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
