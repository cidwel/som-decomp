.setcpu "65816"
.segment "CODE"
.org $63B8
map_control_0f63b8:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
