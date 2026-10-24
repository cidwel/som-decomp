.setcpu "65816"
.segment "CODE"
.org $8934
map_control_0f8934:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
