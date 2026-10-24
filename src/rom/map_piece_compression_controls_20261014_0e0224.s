.setcpu "65816"
.segment "CODE"
.org $0224
map_control_0e0224:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
