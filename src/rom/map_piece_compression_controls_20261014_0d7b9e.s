.setcpu "65816"
.segment "CODE"
.org $7B9E
map_control_0d7b9e:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E4 ; previous-row copy count
