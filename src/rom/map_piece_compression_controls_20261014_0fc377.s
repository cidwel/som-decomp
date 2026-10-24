.setcpu "65816"
.segment "CODE"
.org $C377
map_control_0fc377:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
