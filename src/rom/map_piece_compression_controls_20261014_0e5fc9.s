.setcpu "65816"
.segment "CODE"
.org $5FC9
map_control_0e5fc9:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
