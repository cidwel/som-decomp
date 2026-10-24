.setcpu "65816"
.segment "CODE"
.org $CD5B
map_control_0dcd5b:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
