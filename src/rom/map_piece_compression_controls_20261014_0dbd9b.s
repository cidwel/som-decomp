.setcpu "65816"
.segment "CODE"
.org $BD9B
map_control_0dbd9b:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
