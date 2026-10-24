.setcpu "65816"
.segment "CODE"
.org $C68B
map_control_0ec68b:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E3 ; previous-row copy count
