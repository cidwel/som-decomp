.setcpu "65816"
.segment "CODE"
.org $F5D2
map_control_0df5d2:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
