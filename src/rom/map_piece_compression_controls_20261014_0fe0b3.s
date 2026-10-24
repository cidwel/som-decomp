.setcpu "65816"
.segment "CODE"
.org $E0B3
map_control_0fe0b3:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $BA ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
