.setcpu "65816"
.segment "CODE"
.org $C244
map_control_0fc244:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
