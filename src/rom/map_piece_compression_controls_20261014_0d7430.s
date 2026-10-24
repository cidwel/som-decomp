.setcpu "65816"
.segment "CODE"
.org $7430
map_control_0d7430:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E4 ; previous-row copy count
