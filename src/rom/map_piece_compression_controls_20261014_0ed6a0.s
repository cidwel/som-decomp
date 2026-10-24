.setcpu "65816"
.segment "CODE"
.org $D6A0
map_control_0ed6a0:
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E5 ; previous-row copy count
