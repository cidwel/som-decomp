.setcpu "65816"
.segment "CODE"
.org $4A49
map_control_0c4a49:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
