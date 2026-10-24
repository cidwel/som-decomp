.setcpu "65816"
.segment "CODE"
.org $FA3B
map_control_0ffa3b:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
