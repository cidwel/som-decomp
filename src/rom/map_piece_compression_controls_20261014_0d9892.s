.setcpu "65816"
.segment "CODE"
.org $9892
map_control_0d9892:
    .byte $E4 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
