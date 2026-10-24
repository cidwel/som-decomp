.setcpu "65816"
.segment "CODE"
.org $436E
map_control_0d436e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
