.setcpu "65816"
.segment "CODE"
.org $7BB3
map_control_0d7bb3:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
