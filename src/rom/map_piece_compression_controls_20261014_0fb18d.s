.setcpu "65816"
.segment "CODE"
.org $B18D
map_control_0fb18d:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
