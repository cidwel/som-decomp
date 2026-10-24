.setcpu "65816"
.segment "CODE"
.org $2622
map_control_0f2622:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E5 ; previous-row copy count
