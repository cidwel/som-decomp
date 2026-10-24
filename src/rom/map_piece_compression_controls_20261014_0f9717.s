.setcpu "65816"
.segment "CODE"
.org $9717
map_control_0f9717:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E1 ; previous-row copy count
