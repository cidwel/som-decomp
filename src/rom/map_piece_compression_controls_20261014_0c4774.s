.setcpu "65816"
.segment "CODE"
.org $4774
map_control_0c4774:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
