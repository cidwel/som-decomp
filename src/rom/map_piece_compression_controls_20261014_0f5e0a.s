.setcpu "65816"
.segment "CODE"
.org $5E0A
map_control_0f5e0a:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E7 ; previous-row copy count
