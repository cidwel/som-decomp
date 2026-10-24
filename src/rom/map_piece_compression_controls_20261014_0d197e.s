.setcpu "65816"
.segment "CODE"
.org $197E
map_control_0d197e:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E1 ; previous-row copy count
