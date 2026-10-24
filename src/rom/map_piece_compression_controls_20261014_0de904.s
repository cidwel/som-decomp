.setcpu "65816"
.segment "CODE"
.org $E904
map_control_0de904:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
