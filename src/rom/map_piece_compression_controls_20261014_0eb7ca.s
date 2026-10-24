.setcpu "65816"
.segment "CODE"
.org $B7CA
map_control_0eb7ca:
    .byte $EC ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
