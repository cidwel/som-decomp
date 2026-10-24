.setcpu "65816"
.segment "CODE"
.org $2A66
map_control_0f2a66:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B4 ; row-distance/count
