.setcpu "65816"
.segment "CODE"
.org $A229
map_control_0da229:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
