.setcpu "65816"
.segment "CODE"
.org $4224
map_control_0f4224:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E6 ; previous-row copy count
