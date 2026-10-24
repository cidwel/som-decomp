.setcpu "65816"
.segment "CODE"
.org $8821
map_control_0e8821:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
