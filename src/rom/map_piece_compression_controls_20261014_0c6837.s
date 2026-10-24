.setcpu "65816"
.segment "CODE"
.org $6837
map_control_0c6837:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
