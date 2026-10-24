.setcpu "65816"
.segment "CODE"
.org $EE8C
map_control_0dee8c:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E4 ; previous-row copy count
