.setcpu "65816"
.segment "CODE"
.org $569A
map_control_0e569a:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
