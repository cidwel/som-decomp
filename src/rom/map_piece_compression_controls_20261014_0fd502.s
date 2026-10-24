.setcpu "65816"
.segment "CODE"
.org $D502
map_control_0fd502:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
