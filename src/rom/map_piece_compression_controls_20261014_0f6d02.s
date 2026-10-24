.setcpu "65816"
.segment "CODE"
.org $6D02
map_control_0f6d02:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E1 ; previous-row copy count
