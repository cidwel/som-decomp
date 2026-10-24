.setcpu "65816"
.segment "CODE"
.org $D5BA
map_control_0fd5ba:
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
