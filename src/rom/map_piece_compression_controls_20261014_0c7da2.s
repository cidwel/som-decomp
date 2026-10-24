.setcpu "65816"
.segment "CODE"
.org $7DA2
map_control_0c7da2:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
