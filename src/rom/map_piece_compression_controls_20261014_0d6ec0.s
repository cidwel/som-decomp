.setcpu "65816"
.segment "CODE"
.org $6EC0
map_control_0d6ec0:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
