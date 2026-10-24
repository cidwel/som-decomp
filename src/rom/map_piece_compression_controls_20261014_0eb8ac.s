.setcpu "65816"
.segment "CODE"
.org $B8AC
map_control_0eb8ac:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E1 ; previous-row copy count
