.setcpu "65816"
.segment "CODE"
.org $8640
map_control_0f8640:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E7 ; previous-row copy count
