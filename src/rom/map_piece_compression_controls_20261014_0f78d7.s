.setcpu "65816"
.segment "CODE"
.org $78D7
map_control_0f78d7:
    .byte $EB ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
