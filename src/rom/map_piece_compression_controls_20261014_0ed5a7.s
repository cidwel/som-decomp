.setcpu "65816"
.segment "CODE"
.org $D5A7
map_control_0ed5a7:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $77 ; row-distance/count
