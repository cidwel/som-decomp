.setcpu "65816"
.segment "CODE"
.org $567A
map_control_0f567a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
