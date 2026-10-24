.setcpu "65816"
.segment "CODE"
.org $B11B
map_control_0fb11b:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B1 ; row-distance/count
