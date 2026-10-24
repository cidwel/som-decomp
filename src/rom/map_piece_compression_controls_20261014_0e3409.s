.setcpu "65816"
.segment "CODE"
.org $3409
map_control_0e3409:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
