.setcpu "65816"
.segment "CODE"
.org $78CF
map_control_0f78cf:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
