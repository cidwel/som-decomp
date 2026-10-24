.setcpu "65816"
.segment "CODE"
.org $2BF2
map_control_0d2bf2:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
