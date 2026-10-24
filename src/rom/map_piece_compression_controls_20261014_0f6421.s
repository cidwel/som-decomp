.setcpu "65816"
.segment "CODE"
.org $6421
map_control_0f6421:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
