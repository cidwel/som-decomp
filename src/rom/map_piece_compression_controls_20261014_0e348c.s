.setcpu "65816"
.segment "CODE"
.org $348C
map_control_0e348c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
