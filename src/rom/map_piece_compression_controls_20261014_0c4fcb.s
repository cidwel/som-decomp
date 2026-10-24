.setcpu "65816"
.segment "CODE"
.org $4FCB
map_control_0c4fcb:
    .byte $E9 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E3 ; previous-row copy count
