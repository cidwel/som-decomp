.setcpu "65816"
.segment "CODE"
.org $D13C
map_control_0ed13c:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
