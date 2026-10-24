.setcpu "65816"
.segment "CODE"
.org $1087
map_control_0f1087:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
