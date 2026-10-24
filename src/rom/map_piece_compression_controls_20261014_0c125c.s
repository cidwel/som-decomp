.setcpu "65816"
.segment "CODE"
.org $125C
map_control_0c125c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
