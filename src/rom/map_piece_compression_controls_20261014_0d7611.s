.setcpu "65816"
.segment "CODE"
.org $7611
map_control_0d7611:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
