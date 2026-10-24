.setcpu "65816"
.segment "CODE"
.org $7746
map_control_0f7746:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $8E ; distance low bit/count
