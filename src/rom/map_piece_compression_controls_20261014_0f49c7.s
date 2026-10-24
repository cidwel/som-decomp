.setcpu "65816"
.segment "CODE"
.org $49C7
map_control_0f49c7:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
