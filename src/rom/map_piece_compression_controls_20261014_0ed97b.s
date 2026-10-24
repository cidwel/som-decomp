.setcpu "65816"
.segment "CODE"
.org $D97B
map_control_0ed97b:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
