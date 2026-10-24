.setcpu "65816"
.segment "CODE"
.org $C4D6
map_control_0fc4d6:
    .byte $E0 ; previous-row copy escape
    .byte $61 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
