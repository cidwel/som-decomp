.setcpu "65816"
.segment "CODE"
.org $1CFB
map_control_0e1cfb:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count
