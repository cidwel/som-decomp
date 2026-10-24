.setcpu "65816"
.segment "CODE"
.org $B664
map_control_0fb664:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E4 ; previous-row copy count
