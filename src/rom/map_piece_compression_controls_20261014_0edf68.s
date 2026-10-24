.setcpu "65816"
.segment "CODE"
.org $DF68
map_control_0edf68:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
