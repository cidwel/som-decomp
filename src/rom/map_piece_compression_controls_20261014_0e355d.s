.setcpu "65816"
.segment "CODE"
.org $355D
map_control_0e355d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $6C ; distance low bit/count
