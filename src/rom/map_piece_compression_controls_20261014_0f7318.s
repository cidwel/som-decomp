.setcpu "65816"
.segment "CODE"
.org $7318
map_control_0f7318:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
