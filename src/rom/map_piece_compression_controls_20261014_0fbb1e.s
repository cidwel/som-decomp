.setcpu "65816"
.segment "CODE"
.org $BB1E
map_control_0fbb1e:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
