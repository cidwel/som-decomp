.setcpu "65816"
.segment "CODE"
.org $14F4
map_control_0e14f4:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
