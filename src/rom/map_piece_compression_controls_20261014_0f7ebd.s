.setcpu "65816"
.segment "CODE"
.org $7EBD
map_control_0f7ebd:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E4 ; previous-row copy count
