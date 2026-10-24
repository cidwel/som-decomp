.setcpu "65816"
.segment "CODE"
.org $6B5E
map_control_0e6b5e:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E2 ; previous-row copy count
