.setcpu "65816"
.segment "CODE"
.org $EEF6
map_control_0feef6:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
