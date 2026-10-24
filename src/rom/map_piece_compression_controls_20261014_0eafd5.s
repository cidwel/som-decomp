.setcpu "65816"
.segment "CODE"
.org $AFD5
map_control_0eafd5:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E3 ; previous-row copy count
