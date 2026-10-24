.setcpu "65816"
.segment "CODE"
.org $D204
map_control_0fd204:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E1 ; previous-row copy count
