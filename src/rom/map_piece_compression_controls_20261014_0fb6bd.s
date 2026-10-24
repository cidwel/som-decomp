.setcpu "65816"
.segment "CODE"
.org $B6BD
map_control_0fb6bd:
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $C9 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
