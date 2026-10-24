.setcpu "65816"
.segment "CODE"
.org $2832
map_control_0d2832:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
