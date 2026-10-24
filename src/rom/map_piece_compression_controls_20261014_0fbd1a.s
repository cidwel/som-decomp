.setcpu "65816"
.segment "CODE"
.org $BD1A
map_control_0fbd1a:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
