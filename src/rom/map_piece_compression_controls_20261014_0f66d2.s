.setcpu "65816"
.segment "CODE"
.org $66D2
map_control_0f66d2:
    .byte $E7 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
