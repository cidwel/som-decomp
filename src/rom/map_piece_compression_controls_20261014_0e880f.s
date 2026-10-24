.setcpu "65816"
.segment "CODE"
.org $880F
map_control_0e880f:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
