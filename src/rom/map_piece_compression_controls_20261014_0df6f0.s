.setcpu "65816"
.segment "CODE"
.org $F6F0
map_control_0df6f0:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
