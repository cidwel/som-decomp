.setcpu "65816"
.segment "CODE"
.org $9AB2
map_control_0f9ab2:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
