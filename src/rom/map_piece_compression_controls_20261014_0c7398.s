.setcpu "65816"
.segment "CODE"
.org $7398
map_control_0c7398:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
