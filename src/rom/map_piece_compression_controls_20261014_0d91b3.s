.setcpu "65816"
.segment "CODE"
.org $91B3
map_control_0d91b3:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
