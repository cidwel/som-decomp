.setcpu "65816"
.segment "CODE"
.org $82D8
map_control_0f82d8:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
