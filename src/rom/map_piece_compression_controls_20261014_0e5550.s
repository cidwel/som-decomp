.setcpu "65816"
.segment "CODE"
.org $5550
map_control_0e5550:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
