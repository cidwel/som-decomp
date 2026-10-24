.setcpu "65816"
.segment "CODE"
.org $3A50
map_control_0c3a50:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
