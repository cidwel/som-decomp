.setcpu "65816"
.segment "CODE"
.org $0ECD
map_control_0e0ecd:
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
