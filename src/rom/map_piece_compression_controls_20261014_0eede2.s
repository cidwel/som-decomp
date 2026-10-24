.setcpu "65816"
.segment "CODE"
.org $EDE2
map_control_0eede2:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
