.setcpu "65816"
.segment "CODE"
.org $61AC
map_control_0f61ac:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
