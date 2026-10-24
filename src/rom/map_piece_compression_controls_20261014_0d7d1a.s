.setcpu "65816"
.segment "CODE"
.org $7D1A
map_control_0d7d1a:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
