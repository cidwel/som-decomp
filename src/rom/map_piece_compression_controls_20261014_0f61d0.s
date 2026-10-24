.setcpu "65816"
.segment "CODE"
.org $61D0
map_control_0f61d0:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
