.setcpu "65816"
.segment "CODE"
.org $3E3B
map_control_0c3e3b:
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E1 ; previous-row copy count
