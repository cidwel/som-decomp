.setcpu "65816"
.segment "CODE"
.org $C37E
map_control_0fc37e:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $63 ; row-distance/count
