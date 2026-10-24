.setcpu "65816"
.segment "CODE"
.org $BDCC
map_control_0fbdcc:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E6 ; previous-row copy count
