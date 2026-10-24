.setcpu "65816"
.segment "CODE"
.org $03CA
map_control_0f03ca:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
