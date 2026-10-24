.setcpu "65816"
.segment "CODE"
.org $203C
map_control_0e203c:
    .byte $E7 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E3 ; previous-row copy count
