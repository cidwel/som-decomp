.setcpu "65816"
.segment "CODE"
.org $7BC6
map_control_0c7bc6:
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $5A ; row-distance/count
