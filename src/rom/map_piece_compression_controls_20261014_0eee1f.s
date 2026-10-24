.setcpu "65816"
.segment "CODE"
.org $EE1F
map_control_0eee1f:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
