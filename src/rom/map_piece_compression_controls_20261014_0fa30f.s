.setcpu "65816"
.segment "CODE"
.org $A30F
map_control_0fa30f:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
