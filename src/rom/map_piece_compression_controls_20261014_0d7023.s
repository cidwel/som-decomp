.setcpu "65816"
.segment "CODE"
.org $7023
map_control_0d7023:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E7 ; previous-row copy count
