.setcpu "65816"
.segment "CODE"
.org $3E49
map_control_0c3e49:
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E1 ; previous-row copy count
