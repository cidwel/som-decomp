.setcpu "65816"
.segment "CODE"
.org $CA6C
map_control_0fca6c:
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E4 ; previous-row copy count
