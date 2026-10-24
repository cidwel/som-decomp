.setcpu "65816"
.segment "CODE"
.org $8B14
map_control_0f8b14:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
