.setcpu "65816"
.segment "CODE"
.org $7C4B
map_control_0d7c4b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E4 ; previous-row copy count
