.setcpu "65816"
.segment "CODE"
.org $EEA2
map_control_0feea2:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
