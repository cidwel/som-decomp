.setcpu "65816"
.segment "CODE"
.org $2BF1
map_control_0f2bf1:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
