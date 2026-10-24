.setcpu "65816"
.segment "CODE"
.org $916B
map_control_0c916b:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
