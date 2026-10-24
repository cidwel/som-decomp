.setcpu "65816"
.segment "CODE"
.org $F227
map_control_0ff227:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E1 ; previous-row copy count
