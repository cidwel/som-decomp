.setcpu "65816"
.segment "CODE"
.org $8ECB
map_control_0e8ecb:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
