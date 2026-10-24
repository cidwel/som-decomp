.setcpu "65816"
.segment "CODE"
.org $3650
map_control_0d3650:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
