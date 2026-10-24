.setcpu "65816"
.segment "CODE"
.org $EB78
map_control_0eeb78:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
