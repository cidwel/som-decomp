.setcpu "65816"
.segment "CODE"
.org $76E0
map_control_0f76e0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
