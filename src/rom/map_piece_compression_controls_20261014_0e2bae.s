.setcpu "65816"
.segment "CODE"
.org $2BAE
map_control_0e2bae:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E7 ; previous-row copy count
