.setcpu "65816"
.segment "CODE"
.org $C3E1
map_control_0ec3e1:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
