.setcpu "65816"
.segment "CODE"
.org $834E
map_control_0e834e:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
