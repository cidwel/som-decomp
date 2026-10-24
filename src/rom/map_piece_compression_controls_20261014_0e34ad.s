.setcpu "65816"
.segment "CODE"
.org $34AD
map_control_0e34ad:
    .byte $EA ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
