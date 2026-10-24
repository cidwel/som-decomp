.setcpu "65816"
.segment "CODE"
.org $6D09
map_control_0f6d09:
    .byte $E9 ; backreference distance high bits
    .byte $92 ; distance low bit/count
    .byte $E1 ; previous-row copy count
