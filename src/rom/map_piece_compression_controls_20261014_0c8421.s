.setcpu "65816"
.segment "CODE"
.org $8421
map_control_0c8421:
    .byte $F3 ; progressive-copy count
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $4E ; distance low bit/count
