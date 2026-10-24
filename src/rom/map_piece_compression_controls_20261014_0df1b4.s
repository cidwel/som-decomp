.setcpu "65816"
.segment "CODE"
.org $F1B4
map_control_0df1b4:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
