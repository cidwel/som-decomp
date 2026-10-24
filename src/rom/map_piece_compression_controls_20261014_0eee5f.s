.setcpu "65816"
.segment "CODE"
.org $EE5F
map_control_0eee5f:
    .byte $E4 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
