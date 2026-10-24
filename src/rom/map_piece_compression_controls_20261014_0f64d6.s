.setcpu "65816"
.segment "CODE"
.org $64D6
map_control_0f64d6:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
