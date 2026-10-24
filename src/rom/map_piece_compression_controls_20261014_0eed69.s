.setcpu "65816"
.segment "CODE"
.org $ED69
map_control_0eed69:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
