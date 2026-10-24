.setcpu "65816"
.segment "CODE"
.org $1115
map_control_0e1115:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
