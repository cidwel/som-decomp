.setcpu "65816"
.segment "CODE"
.org $76B4
map_control_0d76b4:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2C ; distance low bit/count
