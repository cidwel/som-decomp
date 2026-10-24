.setcpu "65816"
.segment "CODE"
.org $1209
map_control_0e1209:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $4A ; distance low bit/count
