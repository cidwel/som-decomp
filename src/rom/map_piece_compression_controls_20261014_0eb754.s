.setcpu "65816"
.segment "CODE"
.org $B754
map_control_0eb754:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E4 ; previous-row copy count
