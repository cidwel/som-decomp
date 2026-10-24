.setcpu "65816"
.segment "CODE"
.org $97DC
map_control_0d97dc:
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
