.setcpu "65816"
.segment "CODE"
.org $497D
map_control_0f497d:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
