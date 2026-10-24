.setcpu "65816"
.segment "CODE"
.org $DE06
map_control_0ede06:
    .byte $EA ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
