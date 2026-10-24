.setcpu "65816"
.segment "CODE"
.org $61C8
map_control_0f61c8:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
