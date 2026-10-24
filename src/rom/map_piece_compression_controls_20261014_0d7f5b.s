.setcpu "65816"
.segment "CODE"
.org $7F5B
map_control_0d7f5b:
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
