.setcpu "65816"
.segment "CODE"
.org $74DD
map_control_0f74dd:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
