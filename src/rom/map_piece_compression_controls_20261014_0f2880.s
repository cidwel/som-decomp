.setcpu "65816"
.segment "CODE"
.org $2880
map_control_0f2880:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
