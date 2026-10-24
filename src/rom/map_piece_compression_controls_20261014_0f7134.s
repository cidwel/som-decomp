.setcpu "65816"
.segment "CODE"
.org $7134
map_control_0f7134:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E7 ; previous-row copy count
