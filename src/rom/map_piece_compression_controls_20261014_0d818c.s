.setcpu "65816"
.segment "CODE"
.org $818C
map_control_0d818c:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
