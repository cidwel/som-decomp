.setcpu "65816"
.segment "CODE"
.org $BA6C
map_control_0eba6c:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
