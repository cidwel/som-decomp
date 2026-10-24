.setcpu "65816"
.segment "CODE"
.org $68BF
map_control_0f68bf:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
