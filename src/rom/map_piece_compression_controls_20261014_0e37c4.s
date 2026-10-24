.setcpu "65816"
.segment "CODE"
.org $37C4
map_control_0e37c4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
