.setcpu "65816"
.segment "CODE"
.org $AA1E
map_control_0eaa1e:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
