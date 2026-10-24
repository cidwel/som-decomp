.setcpu "65816"
.segment "CODE"
.org $28E3
map_control_0c28e3:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
