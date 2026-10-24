.setcpu "65816"
.segment "CODE"
.org $2978
map_control_0e2978:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
