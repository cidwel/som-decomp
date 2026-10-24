.setcpu "65816"
.segment "CODE"
.org $59A1
map_control_0c59a1:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
