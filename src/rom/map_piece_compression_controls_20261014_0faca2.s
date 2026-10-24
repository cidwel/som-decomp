.setcpu "65816"
.segment "CODE"
.org $ACA2
map_control_0faca2:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
