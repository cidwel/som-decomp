.setcpu "65816"
.segment "CODE"
.org $B66B
map_control_0fb66b:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
