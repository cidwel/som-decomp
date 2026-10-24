.setcpu "65816"
.segment "CODE"
.org $3285
map_control_0f3285:
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
