.setcpu "65816"
.segment "CODE"
.org $71EB
map_control_0d71eb:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E5 ; previous-row copy count
