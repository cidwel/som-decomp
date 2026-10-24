.setcpu "65816"
.segment "CODE"
.org $7158
map_control_0f7158:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
