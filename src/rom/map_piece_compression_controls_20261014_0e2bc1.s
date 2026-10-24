.setcpu "65816"
.segment "CODE"
.org $2BC1
map_control_0e2bc1:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E7 ; previous-row copy count
