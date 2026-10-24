.setcpu "65816"
.segment "CODE"
.org $B4D5
map_control_0db4d5:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E5 ; previous-row copy count
