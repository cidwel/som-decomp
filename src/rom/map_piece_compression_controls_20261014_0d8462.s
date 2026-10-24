.setcpu "65816"
.segment "CODE"
.org $8462
map_control_0d8462:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
