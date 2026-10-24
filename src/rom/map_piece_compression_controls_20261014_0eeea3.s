.setcpu "65816"
.segment "CODE"
.org $EEA3
map_control_0eeea3:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E5 ; previous-row copy count
