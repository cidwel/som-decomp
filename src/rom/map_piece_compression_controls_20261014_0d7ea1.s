.setcpu "65816"
.segment "CODE"
.org $7EA1
map_control_0d7ea1:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
