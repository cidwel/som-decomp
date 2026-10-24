.setcpu "65816"
.segment "CODE"
.org $4C80
map_control_0f4c80:
    .byte $EA ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AA ; row-distance/count
