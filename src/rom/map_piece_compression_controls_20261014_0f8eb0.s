.setcpu "65816"
.segment "CODE"
.org $8EB0
map_control_0f8eb0:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E4 ; previous-row copy count
