.setcpu "65816"
.segment "CODE"
.org $2D35
map_control_0c2d35:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E3 ; previous-row copy count
