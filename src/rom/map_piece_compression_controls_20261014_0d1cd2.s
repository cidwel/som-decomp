.setcpu "65816"
.segment "CODE"
.org $1CD2
map_control_0d1cd2:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
