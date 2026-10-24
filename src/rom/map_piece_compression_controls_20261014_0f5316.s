.setcpu "65816"
.segment "CODE"
.org $5316
map_control_0f5316:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
