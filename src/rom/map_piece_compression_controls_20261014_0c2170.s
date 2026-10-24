.setcpu "65816"
.segment "CODE"
.org $2170
map_control_0c2170:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
