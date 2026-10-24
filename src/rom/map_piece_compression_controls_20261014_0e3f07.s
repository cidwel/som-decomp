.setcpu "65816"
.segment "CODE"
.org $3F07
map_control_0e3f07:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
