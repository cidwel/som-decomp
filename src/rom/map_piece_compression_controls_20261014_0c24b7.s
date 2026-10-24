.setcpu "65816"
.segment "CODE"
.org $24B7
map_control_0c24b7:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7E ; row-distance/count
