.setcpu "65816"
.segment "CODE"
.org $E699
map_control_0ee699:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
