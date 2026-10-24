.setcpu "65816"
.segment "CODE"
.org $2C26
map_control_0d2c26:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
