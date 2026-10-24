.setcpu "65816"
.segment "CODE"
.org $F145
map_control_0ef145:
    .byte $E5 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
