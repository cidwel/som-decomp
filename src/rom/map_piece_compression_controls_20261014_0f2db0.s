.setcpu "65816"
.segment "CODE"
.org $2DB0
map_control_0f2db0:
    .byte $E3 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
