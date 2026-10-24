.setcpu "65816"
.segment "CODE"
.org $6224
map_control_0e6224:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
