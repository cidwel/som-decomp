.setcpu "65816"
.segment "CODE"
.org $8B4B
map_control_0e8b4b:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
