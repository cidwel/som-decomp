.setcpu "65816"
.segment "CODE"
.org $2AE4
map_control_0c2ae4:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
