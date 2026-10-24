.setcpu "65816"
.segment "CODE"
.org $F052
map_control_0ef052:
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
    .byte $E2 ; previous-row copy count
