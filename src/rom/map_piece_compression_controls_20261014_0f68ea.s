.setcpu "65816"
.segment "CODE"
.org $68EA
map_control_0f68ea:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
