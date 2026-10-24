.setcpu "65816"
.segment "CODE"
.org $4CB6
map_control_0d4cb6:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E4 ; previous-row copy count
