.setcpu "65816"
.segment "CODE"
.org $3324
map_control_0d3324:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
