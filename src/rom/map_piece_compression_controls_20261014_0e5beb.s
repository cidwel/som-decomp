.setcpu "65816"
.segment "CODE"
.org $5BEB
map_control_0e5beb:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
