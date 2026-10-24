.setcpu "65816"
.segment "CODE"
.org $61BF
map_control_0f61bf:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
