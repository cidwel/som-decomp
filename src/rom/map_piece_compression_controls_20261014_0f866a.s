.setcpu "65816"
.segment "CODE"
.org $866A
map_control_0f866a:
    .byte $E2 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E7 ; previous-row copy count
