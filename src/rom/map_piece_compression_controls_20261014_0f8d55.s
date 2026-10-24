.setcpu "65816"
.segment "CODE"
.org $8D55
map_control_0f8d55:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
