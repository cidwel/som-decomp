.setcpu "65816"
.segment "CODE"
.org $942B
map_control_0d942b:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
