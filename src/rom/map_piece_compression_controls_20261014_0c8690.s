.setcpu "65816"
.segment "CODE"
.org $8690
map_control_0c8690:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
