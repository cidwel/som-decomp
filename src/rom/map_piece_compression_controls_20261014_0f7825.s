.setcpu "65816"
.segment "CODE"
.org $7825
map_control_0f7825:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
