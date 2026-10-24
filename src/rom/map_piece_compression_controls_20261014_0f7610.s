.setcpu "65816"
.segment "CODE"
.org $7610
map_control_0f7610:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
