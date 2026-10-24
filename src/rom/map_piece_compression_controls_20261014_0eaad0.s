.setcpu "65816"
.segment "CODE"
.org $AAD0
map_control_0eaad0:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
