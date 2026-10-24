.setcpu "65816"
.segment "CODE"
.org $2D7D
map_control_0d2d7d:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2F ; distance low bit/count
