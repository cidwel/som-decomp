.setcpu "65816"
.segment "CODE"
.org $DF71
map_control_0edf71:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $5F ; row-distance/count
