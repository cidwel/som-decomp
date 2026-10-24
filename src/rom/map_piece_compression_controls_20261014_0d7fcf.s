.setcpu "65816"
.segment "CODE"
.org $7FCF
map_control_0d7fcf:
    .byte $EE ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
