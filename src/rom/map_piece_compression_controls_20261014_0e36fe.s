.setcpu "65816"
.segment "CODE"
.org $36FE
map_control_0e36fe:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
