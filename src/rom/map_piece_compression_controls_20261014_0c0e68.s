.setcpu "65816"
.segment "CODE"
.org $0E68
map_control_0c0e68:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $CB ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $BF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $D7 ; row-distance/count
