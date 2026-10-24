.setcpu "65816"
.segment "CODE"
.org $8931
map_control_0e8931:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
