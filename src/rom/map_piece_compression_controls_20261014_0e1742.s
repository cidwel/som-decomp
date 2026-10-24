.setcpu "65816"
.segment "CODE"
.org $1742
map_control_0e1742:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
