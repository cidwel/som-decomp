.setcpu "65816"
.segment "CODE"
.org $CF19
map_control_0dcf19:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7D ; row-distance/count
