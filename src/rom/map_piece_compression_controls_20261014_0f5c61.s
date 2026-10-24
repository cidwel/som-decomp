.setcpu "65816"
.segment "CODE"
.org $5C61
map_control_0f5c61:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E3 ; previous-row copy count
