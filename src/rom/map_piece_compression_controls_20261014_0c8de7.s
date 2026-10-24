.setcpu "65816"
.segment "CODE"
.org $8DE7
map_control_0c8de7:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $5A ; row-distance/count
