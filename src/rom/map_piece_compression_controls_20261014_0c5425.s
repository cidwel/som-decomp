.setcpu "65816"
.segment "CODE"
.org $5425
map_control_0c5425:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
