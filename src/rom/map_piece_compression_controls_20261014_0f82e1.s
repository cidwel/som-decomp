.setcpu "65816"
.segment "CODE"
.org $82E1
map_control_0f82e1:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
