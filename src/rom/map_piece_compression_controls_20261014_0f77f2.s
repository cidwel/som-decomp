.setcpu "65816"
.segment "CODE"
.org $77F2
map_control_0f77f2:
    .byte $E9 ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $51 ; row-distance/count
