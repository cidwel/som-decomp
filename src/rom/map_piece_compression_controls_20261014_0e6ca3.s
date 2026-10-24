.setcpu "65816"
.segment "CODE"
.org $6CA3
map_control_0e6ca3:
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B1 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
