.setcpu "65816"
.segment "CODE"
.org $ECC1
map_control_0fecc1:
    .byte $E2 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
