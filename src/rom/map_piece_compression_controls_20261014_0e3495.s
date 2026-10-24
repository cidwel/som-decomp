.setcpu "65816"
.segment "CODE"
.org $3495
map_control_0e3495:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
