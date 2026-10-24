.setcpu "65816"
.segment "CODE"
.org $1C76
map_control_0e1c76:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
