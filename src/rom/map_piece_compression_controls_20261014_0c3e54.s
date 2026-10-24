.setcpu "65816"
.segment "CODE"
.org $3E54
map_control_0c3e54:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
