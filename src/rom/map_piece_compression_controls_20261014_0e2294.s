.setcpu "65816"
.segment "CODE"
.org $2294
map_control_0e2294:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
