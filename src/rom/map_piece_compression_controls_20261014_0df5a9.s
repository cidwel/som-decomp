.setcpu "65816"
.segment "CODE"
.org $F5A9
map_control_0df5a9:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
