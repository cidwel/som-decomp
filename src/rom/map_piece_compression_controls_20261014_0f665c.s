.setcpu "65816"
.segment "CODE"
.org $665C
map_control_0f665c:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E5 ; previous-row copy count
