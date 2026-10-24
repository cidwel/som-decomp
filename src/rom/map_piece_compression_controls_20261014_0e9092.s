.setcpu "65816"
.segment "CODE"
.org $9092
map_control_0e9092:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
