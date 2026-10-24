.setcpu "65816"
.segment "CODE"
.org $D154
map_control_0fd154:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
