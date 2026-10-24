.setcpu "65816"
.segment "CODE"
.org $CE10
map_control_0ece10:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
