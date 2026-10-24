.setcpu "65816"
.segment "CODE"
.org $92A5
map_control_0e92a5:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
