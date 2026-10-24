.setcpu "65816"
.segment "CODE"
.org $F9B1
map_control_0df9b1:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
