.setcpu "65816"
.segment "CODE"
.org $8F48
map_control_0e8f48:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
