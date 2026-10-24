.setcpu "65816"
.segment "CODE"
.org $54B6
map_control_0d54b6:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
